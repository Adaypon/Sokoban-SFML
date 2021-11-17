#include "GameState.hpp"
#include "Player.hpp"

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
		return CellData::Wall;
	case 'B':   // box
		return CellData::Box;
	case 'Q':   // box on goal
		return CellData::BoxOnGoal;
	case '.':   // free cell
		return CellData::Free;
	case 'x':   // goal
		return CellData::Goal;
	case '@':
		return CellData::Player;
	default:
		return -1; // just for test
	}
}

void GameState::init() {
	_context->_assets->AddTexture("Background", "assets/sprites/bg.png", true);
	_context->_assets->AddTexture("Wall", "assets/sprites/wall.png");
	_context->_assets->AddTexture("Box", "assets/sprites/box.png");
	_context->_assets->AddTexture("Free", "assets/sprites/free.png");
	_context->_assets->AddTexture("Tileset", "assets/sprites/tileset.png");
	_context->_assets->AddTexture("Player", "assets/sprites/player.png");

	_background.setTexture(_context->_assets->getTexture("Background"));
	_background.setTextureRect(_context->_window->getViewport(_context->_window->getDefaultView()));

	_sprite.setTexture(_context->_assets->getTexture("Tileset"));
	//createObject(new Player(_context)); // TODO fix E0079
	createObject(new Entity(_context, "Player"));
}

void GameState::handleInput(const sf::Time deltaTime) {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		_objects[0]->move(deltaTime, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		_objects[0]->move(deltaTime, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		_objects[0]->move(deltaTime, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		_objects[0]->move(deltaTime, 0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		_objects[0]->getSprite().setPosition(10, 10);
	}
	
}

void GameState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	std::cout << "Hello from GameState" << std::endl;
	for (Entity* o : _objects) {
		o->update(deltaTime);
	}
	//_player.update(deltaTime);
}

void GameState::render(sf::RenderWindow* window) {
	_context->_window->draw(_background);

	// level
	for (int i = 0; i < sizeOfGridLine; ++i) {
		for (int j = 0; j < sizeOfGridLine; ++j) {
			int numOfSprite = getNumOfSprite(i, j);
			_sprite.setTextureRect(sf::IntRect(numOfSprite * widthOfSprite, 0, widthOfSprite, widthOfSprite));
			_sprite.setPosition(static_cast<float>(j) * widthOfSprite, static_cast<float>(i) * widthOfSprite);
			_context->_window->draw(_sprite);
		}
	}

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
