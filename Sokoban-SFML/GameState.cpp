#include "GameState.hpp"

GameState::GameState(Game* game) :
	State(game),
	_shape(100.f)
{

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
	_shape.setFillColor(sf::Color::Green);
	_player.update(deltaTime);
}

void GameState::render(sf::RenderWindow* window) {
	window->draw(_shape);
	_player.render(window);
}
