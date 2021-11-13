#include "GameState.hpp"

GameState::GameState(std::shared_ptr<Context>& context) :
	_context(context)
{

}

GameState::~GameState() {

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


	_background.setTexture(_context->_assets->getTexture("Background"));
	_background.setTextureRect(_context->_window->getViewport(_context->_window->getDefaultView()));

	_sprite.setTexture(_context->_assets->getTexture("Tileset"));
}

void GameState::handleInput(const sf::Time deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		_player.move(deltaTime, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		_player.move(deltaTime, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		_player.move(deltaTime, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		_player.move(deltaTime, 0.f, 1.f);
	}
}

void GameState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	std::cout << "Hello from GameState" << std::endl;
	_player.update(deltaTime);
}

void GameState::render(sf::RenderWindow* window) {
	_context->_window->draw(_background);

	// level
	for (int i = 0; i < sizeOfGridLine; ++i) {
		for (int j = 0; j < sizeOfGridLine; ++j) {
			int numOfSprite = getNumOfSprite(i, j);
			_sprite.setTextureRect(sf::IntRect(numOfSprite * widthOfSprite, 0, widthOfSprite, widthOfSprite));
			_sprite.setPosition(j * widthOfSprite, i * widthOfSprite);
			_context->_window->draw(_sprite);
		}
	}

	_player.render(_context->_window.get());
}
