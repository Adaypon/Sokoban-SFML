#include "GameState.hpp"

GameState::GameState() :
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
	_player.update(deltaTime);
}

void GameState::render(sf::RenderWindow* window) {
	window->draw(_shape);
	_player.render(window);
}
