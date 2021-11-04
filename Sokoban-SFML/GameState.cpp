#include "GameState.hpp"

GameState::GameState(Game* game) :
	State(game),
	_shape(100.f)
{

}

GameState::~GameState() {

}


void GameState::handleInput(const sf::Time deltaTime) {

}

void GameState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	std::cout << "Hello from GameState" << std::endl;
	_shape.setFillColor(sf::Color::Green);
}

void GameState::render(sf::RenderWindow* window) {
	window->draw(_shape);
}
