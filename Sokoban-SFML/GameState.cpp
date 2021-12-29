#include "GameState.hpp"
#include "PauseGameState.hpp"

float ftime = 0;
void timer(int x) {
	sf::Clock clock;
	while (ftime < x) {
		ftime = clock.getElapsedTime().asSeconds();
	}
	ftime = 0;
}

GameState::GameState(std::shared_ptr<Context>& context, int levelNum) :
	_context(context),
	_levelNum(levelNum),
	_win(false),
	_boxTrouble(false),
	_boardData()
{
	
}
/*
GameState::~GameState() {
	for (Entity* o : _objects) {
		delete o;
	}
	_objects.clear();
}
*/
int GameState::getNumOfSprite(int i, int j) {
	switch (_boardData[i][j]) {
	case '#':   // wall
		return CellData::WallCell;
	case 'B':   // box
		return CellData::BoxCell;
	case 'Q':   // box on goal
		return CellData::BoxOnGoalCell;
	case '.':   // free cell
		return CellData::FreeCell;
	case 'x':   // goal
		return CellData::GoalCell;
	case '@':	// player
		return CellData::PlayerCell;
	default:
		return -1;
	}
}

void GameState::init() {
	const std::string fileName = "lvl_" + std::to_string(_levelNum) + ".txt";
	std::cout << "Trying to open " << fileName << std::endl;
	std::ifstream fin;
	fin.open("levels/" + fileName);
	if (!fin.is_open()) {
		std::cerr << "Can't open file" << std::endl; // TODO think about what should it do after that
		_context->_states->popState();
		return;
	}
	std::string strLine;
	while (std::getline(fin, strLine)) {
		if (strLine.size() > 0) {
			_boardData.push_back(strLine);
		}
	}
	fin.close();

	_widthOfGridLine = _boardData[0].size();
	_heightOfGridLine = _boardData.size();


	_context->_assets->AddTexture("Background", "assets/sprites/bg.png", true);
	_context->_assets->AddTexture("Wall", "assets/sprites/wall.png");
	_context->_assets->AddTexture("Box", "assets/sprites/box.png");
	_context->_assets->AddTexture("Free", "assets/sprites/free.png");
	_context->_assets->AddTexture("Goal", "assets/sprites/goal.png");
	_context->_assets->AddTexture("Player", "assets/sprites/player_tileset.png");

	_debugText.setFont(_context->_assets->getFont("Main font"));
	_debugText.setCharacterSize(24);
	_debugText.setOutlineThickness(2);
	_debugText.setOutlineColor(sf::Color::Black);
	_debugText.setPosition(_context->_window->getView().getSize().x - 250.f, _context->_window->getView().getSize().y - 150.f);
	_debugText.setString("WASD - move\nESC - pause\nR - restart\nQ - quit\nTab - debug options");

	_background.setTexture(_context->_assets->getTexture("Background"));
	_background.setTextureRect(_context->_window->getViewport(_context->_window->getView()));

	_free.setTexture(_context->_assets->getTexture("Free"));

	_offsetX = _context->_window->getView().getSize().x / 2;
	_offsetY = _context->_window->getView().getSize().y / 2;

	_offsetX -= (_widthOfGridLine / 2.f) * widthOfSprite;
	_offsetY -= (_heightOfGridLine / 2.f) * heightOfSprite;

	// creating objects
	for (int i = 0; i < _heightOfGridLine; ++i) { // y \|/
		for (int j = 0; j < _widthOfGridLine; ++j) { // x ->
			int numOfSprite = getNumOfSprite(i, j);
			if (numOfSprite == CellData::PlayerCell) {
				createObject(new Player(_context, _offsetX + j * widthOfSprite, _offsetY + i * heightOfSprite));
			}
			if (numOfSprite == CellData::WallCell) {
				createObject(new Wall(_context, _offsetX + j * widthOfSprite, _offsetY + i * heightOfSprite));
			}
			if (numOfSprite == CellData::BoxCell) {
				createObject(new Box(_context, _offsetX + j * widthOfSprite, _offsetY + i * heightOfSprite));
			}
			if (numOfSprite == CellData::GoalCell) {
				createObject(new Goal(_context, _offsetX + j * widthOfSprite, _offsetY + i * heightOfSprite));
			}
			if (numOfSprite == CellData::BoxOnGoalCell) {
				createObject(new Goal(_context, _offsetX + j * widthOfSprite, _offsetY + i * heightOfSprite));
				createObject(new Box(_context, _offsetX + j * widthOfSprite, _offsetY + i * heightOfSprite));
			}
		}
	}
}

void GameState::handleInput(const sf::Time deltaTime) {
	
}


void GameState::updateSFMLEvents(sf::Event& SFMLEvent) {
	State::updateSFMLEvents(SFMLEvent);
	if (SFMLEvent.type == sf::Event::KeyPressed) {
		switch (SFMLEvent.key.code)
		{
		case (sf::Keyboard::PageUp):
			if (_levelNum < _levelsCount) {
				_context->_states->addState(std::make_unique<GameState>(_context, ++_levelNum), true);
			}
			break;
		case (sf::Keyboard::PageDown):
			if (_levelNum > 1) {
				_context->_states->addState(std::make_unique<GameState>(_context, --_levelNum), true);
			}
			break;
		case (sf::Keyboard::Q):
			_context->_states->popState();
			break;
		case (sf::Keyboard::Tab):
			_debugText.setPosition(_context->_window->getView().getSize().x - 300.f, _context->_window->getView().getSize().y - 250.f);
			_debugText.setString("WASD - move\nESC - pause\nR - restart\nQ - quit\nPgUp - next level\nPgDn - prev level\nSpacebar - visibility\nNum+ - increase depth\nNum- - decrease depth\nNum0 - bounds of player");
			break;
		case (sf::Keyboard::Escape):
			_context->_states->addState(std::make_unique<PauseGameState>(_context));
			break;
		default:
			break;
		}
	}
	else if (SFMLEvent.type == sf::Event::LostFocus) {
		pause();
	}
}

void GameState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	//std::cout << "Hello from GameState" << std::endl;
	

	if (_win) {
		std::cout << "Win" << std::endl;
		timer(3);
		if (_levelNum >= _levelsCount) {
			_context->_states->popState();
		}
		else {
			_context->_states->addState(std::make_unique<GameState>(_context, ++_levelNum), true);
		}
		
		return;
	}

	// check valid boxes
	// - box may be unmovable in some moments
	// - to check that, we should look, if box is in corner with other solids
	_boxTrouble = false;
	std::vector<Box*> boxes = getAllObjectsOfType<Box*>();

	for (size_t i = 0; i < boxes.size(); ++i) {
		boxes[i]->update(deltaTime);  // for sure it's on goal
		if (!boxes[i]->isAvaliable()) {
			_boxTrouble = true;
			break;
		}
	}
	/*
	for (size_t i = 0; i < boxes.size(); ++i) {
		boxes[i]->update(deltaTime); // for sure it's on goal
		if (!boxes[i]->isOnGoal()) {
			std::cout << "Checking " << i << " box at pos: " << boxes[i]->X() << " " << boxes[i]->Y() << std::endl;
			sf::FloatRect boxBounds = boxes[i]->getSprite().getGlobalBounds();
			sf::FloatRect checkBounds = boxBounds;
			checkBounds.left -= checkBounds.width / 2.f;
			checkBounds.top -= checkBounds.height / 2.f;

			std::vector<SolidObject*> solids = getObjectsAtRect<SolidObject*>(checkBounds);
			if (solids.size() == 4) {
				for (SolidObject* solid : solids) {
					std::cout << "Solid: " << solid->X() << " " << solid->Y() << std::endl;
				}
				_boxTrouble = true;
				break;
			}
			else {
				solids.clear();
			}

			checkBounds.left += checkBounds.width;
			
			solids = getObjectsAtRect<SolidObject*>(checkBounds);
			if (solids.size() == 4) {
				for (SolidObject* solid : solids) {
					std::cout << "Solid: " << solid->X() << " " << solid->Y() << std::endl;
				}
				_boxTrouble = true;
				break;
			}
			else {
				solids.clear();
			}

			checkBounds.top += checkBounds.height;

			solids = getObjectsAtRect<SolidObject*>(checkBounds);
			if (solids.size() == 4) {
				for (SolidObject* solid : solids) {
					std::cout << "Solid: " << solid->X() << " " << solid->Y() << std::endl;
				}
				_boxTrouble = true;
				break;
			}
			else {
				solids.clear();
			}
			

			
			checkBounds.left -= checkBounds.width;

			solids = getObjectsAtRect<SolidObject*>(checkBounds);
			if (solids.size() == 4) {
				for (SolidObject* solid : solids) {
					std::cout << "Solid: " << solid->X() << " " << solid->Y() << std::endl;
				}
				_boxTrouble = true;
				break;
			}
			else {
				solids.clear();
			}
		}
	}
	*/
	if (_boxTrouble) {
		std::cout << "Looks like a trouble!" << std::endl;
		// setting all boxes unavaliable
		for (auto box : boxes) {
			box->setAvaliable(false);
		}
	}
	
	
	// check win
	// - get vector of all objects of type Goal
	// - for every goal get vector of boxes at goal bounds
	// - if boxes.size() != 1 -- break, not winning yet
	// - if bool won == true -- hooray, pop GameState
	std::vector<Goal*> goals = getAllObjectsOfType<Goal*>();
	for (Goal* g : goals) {
		std::vector<Box*> boxes = getObjectsAtRect<Box*>(g->getSprite().getGlobalBounds());
		if (boxes.size() == 1) {
			if (!_win) {
				_win = true;
			}
		}
		else {
			_win = false;
			break;
		}
	}
	

	State::update(deltaTime);

}

void GameState::render() {
	// render background
	_context->_window->draw(_background);
	

	// render grid (free cells)
	for (int i = 0; i < _heightOfGridLine; ++i) {
		for (int j = 0; j < _widthOfGridLine; ++j) {
			if (getNumOfSprite(i, j) != -1) {
				_free.setPosition(_offsetX + static_cast<float>(j) * widthOfSprite, _offsetY + static_cast<float>(i) * heightOfSprite);
				_context->_window->draw(_free);
			}			
		}
	}

	// render objects
	State::render();

	if (_win) {
		sf::Text winTitle;
		winTitle.setFont(_context->_assets->getFont("Main font"));
		winTitle.setString("Level complete!");
		winTitle.setCharacterSize(36);
		winTitle.setOutlineThickness(2);
		winTitle.setOutlineColor(sf::Color::Black);
		winTitle.setOrigin(winTitle.getLocalBounds().width / 2, winTitle.getLocalBounds().height / 2);
		winTitle.setPosition(_context->_window->getView().getSize().x / 2, _context->_window->getView().getSize().y / 2);

		_context->_window->draw(winTitle);
		return;
	}

	_context->_window->draw(_debugText);
	

	

	if (_boxTrouble && !_win) {
		sf::Text boxTroubleText;
		boxTroubleText.setFont(_context->_assets->getFont("Main font"));
		boxTroubleText.setString("Looks like you have a trouble!\nPress R to restart");
		boxTroubleText.setFillColor(sf::Color::Red);
		boxTroubleText.setCharacterSize(24);
		boxTroubleText.setOutlineThickness(2);
		boxTroubleText.setOutlineColor(sf::Color::Black);
		boxTroubleText.setPosition(_context->_window->getView().getSize().x - 375.f, 10);

		_context->_window->draw(boxTroubleText);
	}
	
}

void GameState::pause() {
	_context->_states->addState(std::make_unique<PauseGameState>(_context));
}

void GameState::resume() {

}