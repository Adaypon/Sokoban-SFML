#include "GameState.hpp"

GameState::GameState(std::shared_ptr<Context>& context) :
	_context(context)
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
	switch (board1[i][j]) {
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
	case '@':
		return CellData::PlayerCell;
	default:
		return -1; // just for test
	}
}

void GameState::init() {
	_context->_assets->AddTexture("Background", "assets/sprites/bg.png", true);
	_context->_assets->AddTexture("Wall", "assets/sprites/wall.png");
	_context->_assets->AddTexture("Box", "assets/sprites/box.png");
	_context->_assets->AddTexture("Free", "assets/sprites/free.png");
	_context->_assets->AddTexture("Goal", "assets/sprites/goal.png");
	_context->_assets->AddTexture("Tileset", "assets/sprites/tileset.png");
	_context->_assets->AddTexture("Player", "assets/sprites/player_tileset.png");

	_background.setTexture(_context->_assets->getTexture("Background"));
	_background.setTextureRect(_context->_window->getViewport(_context->_window->getDefaultView()));

	_sprite.setTexture(_context->_assets->getTexture("Tileset"));

	auto windowSize = _context->_window->getSize();
	_offsetX = windowSize.x / 2;
	_offsetY = windowSize.y / 2;

	_offsetX -= (widthOfGridLine / 2.f) * widthOfSprite;
	_offsetY -= (heightOfGridLine / 2.f) * heightOfSprite;


	//createObject(new Box(_context));
	//createObject(new Wall(_context));
	//createObject(new Goal(_context));


	// level
	for (int i = 0; i < heightOfGridLine; ++i) { // y \|/
		for (int j = 0; j < widthOfGridLine; ++j) { // x ->
			int numOfSprite = getNumOfSprite(i, j);
			if (numOfSprite == CellData::PlayerCell) {
				createObject(new Player(_context, _offsetX + j * widthOfSprite, _offsetY + i * heightOfSprite));
				//_objects.back()->getSprite().setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			}
			if (numOfSprite == CellData::WallCell) {
				createObject(new Wall(_context, _offsetX + j * widthOfSprite, _offsetY + i * heightOfSprite));
				//_objects.back()->getSprite().setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			}
			if (numOfSprite == CellData::BoxCell) {
				createObject(new Box(_context, _offsetX + j * widthOfSprite, _offsetY + i * heightOfSprite));
				//_objects.back()->getSprite().setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			}
			if (numOfSprite == CellData::GoalCell) {
				createObject(new Goal(_context, _offsetX + j * widthOfSprite, _offsetY + i * heightOfSprite));
				//_objects.back()->getSprite().setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			}


			//_sprite.setTextureRect(sf::IntRect(numOfSprite * widthOfSprite, 0, widthOfSprite, widthOfSprite));
			//_sprite.setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			//_context->_window->draw(_sprite);

		}
	}
	//createObject(new Player(_context, 0, 0));
}

void GameState::handleInput(const sf::Time deltaTime) {

}

void GameState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	//std::cout << "Hello from GameState" << std::endl;
	
	// check win
	// - get vector of all objects of type Goal
	// - for every goal get vector of boxes at goal bounds
	// - if boxes.size() != 1 -- break, not winning yet
	// - if bool won == true -- hooray, pop GameState
	bool won = true;
	std::vector<Goal*> goals = getAllObjectsOfType<Goal*>();
	for (Goal* g : goals) {
		std::vector<Box*> boxes = getObjectsAtRect<Box*>(g->getSprite().getGlobalBounds());
		if (boxes.size() != 1) {
			won = false;
			break;
		}
	}
	if (won) {
		std::cout << "Win" << std::endl;
		_context->_states->popState();
	}

	State::update(deltaTime);
	
}
/*
bool depthLessComparator(Entity* lhs, Entity* rhs) {
	return lhs->getDepth() < rhs->getDepth();
}
*/
void GameState::render(sf::RenderWindow* window) {
	// render background
	_context->_window->draw(_background);

	// render grid (free cells)
	_sprite.setTextureRect(sf::IntRect(CellData::FreeCell * widthOfSprite, 0, widthOfSprite, heightOfSprite));
	for (int i = 0; i < heightOfGridLine; ++i) {
		for (int j = 0; j < widthOfGridLine; ++j) {
			if (getNumOfSprite(i, j) != -1) {
				_sprite.setPosition(_offsetX + static_cast<float>(j) * widthOfSprite, _offsetY + static_cast<float>(i) * heightOfSprite);
				_context->_window->draw(_sprite);
			}			
		}
	}

	// sorting by depth
	//std::sort(_objects.begin(), _objects.end(), depthLessComparator);

	// render objects
	/*
	for (Entity* o : _objects) {
		o->render(_context->_window.get());
	}
	*/
	State::render(_context->_window.get());

	//_player.render(_context->_window.get());
}

void GameState::pause() {

}

void GameState::resume() {

}
/*
void GameState::createObject(Entity* object) {
	_objects.push_back(object);
}
*/