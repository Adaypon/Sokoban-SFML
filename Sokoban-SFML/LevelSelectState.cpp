#include "LevelSelectState.hpp"

LevelSelectState::LevelSelectState() {

}

LevelSelectState::~LevelSelectState() {

}

void LevelSelectState::init() {

}

void LevelSelectState::handleInput(const sf::Time deltaTime) {
	
}

void LevelSelectState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	std::cout << "Hello from Level Select Screen" << std::endl;
}

void LevelSelectState::render(sf::RenderWindow* window) {

}
