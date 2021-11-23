#include "GameState.hpp"

GameState::GameState(std::shared_ptr<Context>& context) :
	_context(context),
	_objects()
{

}

GameState::~GameState() {
	for (Entity* o : _objects) {
		delete o;
	}
	_objects.clear();
}

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
	_context->_assets->AddTexture("Player", "assets/sprites/player.png");

	_background.setTexture(_context->_assets->getTexture("Background"));
	_background.setTextureRect(_context->_window->getViewport(_context->_window->getDefaultView()));

	_sprite.setTexture(_context->_assets->getTexture("Tileset"));
	
	/*
	createObject(new Box(_context));
	createObject(new Wall(_context));
	createObject(new Goal(_context));
	*/

	// level
	for (int i = 0; i < sizeOfGridLine; ++i) { // y \|/
		for (int j = 0; j < sizeOfGridLine; ++j) { // x ->
			int numOfSprite = getNumOfSprite(i, j);
			if (numOfSprite == CellData::PlayerCell) {
				createObject(new Player(_context, j * widthOfSprite, i * widthOfSprite));
				//_objects.back()->getSprite().setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			}
			if (numOfSprite == CellData::WallCell) {
				createObject(new Wall(_context, j * widthOfSprite, i * widthOfSprite));
				//_objects.back()->getSprite().setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			}
			if (numOfSprite == CellData::BoxCell) {
				createObject(new Box(_context, j * widthOfSprite, i * widthOfSprite));
				//_objects.back()->getSprite().setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			}
			if (numOfSprite == CellData::GoalCell) {
				createObject(new Goal(_context, j * widthOfSprite, i * widthOfSprite));
				//_objects.back()->getSprite().setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			}

			
			/*
			_sprite.setTextureRect(sf::IntRect(numOfSprite * widthOfSprite, 0, widthOfSprite, widthOfSprite));
			_sprite.setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			_context->_window->draw(_sprite);
			*/
		}
	}
	//createObject(new Player(_context, 0, 0));
}

void GameState::handleInput(const sf::Time deltaTime) {
	
}

void GameState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	std::cout << "Hello from GameState" << std::endl;
	for (Entity* o : _objects) {
		o->update(deltaTime);
	}
	//_player.update(deltaTime);
}

bool depthLessComparator(Entity* lhs, Entity* rhs) {
	return lhs->getDepth() < rhs->getDepth();
}

void GameState::render(sf::RenderWindow* window) {
	// render background
	_context->_window->draw(_background);

	// render grid (free cells)
	for (int i = 0; i < sizeOfGridLine; ++i) {
		for (int j = 0; j < sizeOfGridLine; ++j) {
			int numOfSprite = getNumOfSprite(i, j);
			if (numOfSprite == CellData::FreeCell || numOfSprite == CellData::GoalCell || numOfSprite == CellData::PlayerCell) {
				_sprite.setTextureRect(sf::IntRect(CellData::FreeCell * widthOfSprite, 0, widthOfSprite, widthOfSprite));
				_sprite.setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
				_context->_window->draw(_sprite);
			}
		}
	}

	// sorting by depth
	std::sort(_objects.begin(), _objects.end(), depthLessComparator);

	// render objects
	for (Entity* o : _objects) {
		o->render(_context->_window.get());
	}

	//_player.render(_context->_window.get());
}

void GameState::pause() {

}

void GameState::resume() {

}

void GameState::createObject(Entity* object) {
	_objects.push_back(object);
}
