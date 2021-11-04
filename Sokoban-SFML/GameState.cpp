#include "GameState.hpp"

GameState::GameState(Game* game) :
	State(game)
{

}

GameState::~GameState() {

}

void GameState::handleInput(const sf::Time deltaTime) {

}

void GameState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	std::cout << "Hello from GameState" << std::endl;
}

void GameState::render(sf::RenderWindow* window) {

}
