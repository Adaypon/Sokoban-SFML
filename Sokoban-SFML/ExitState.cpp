#include "ExitState.hpp"

ExitState::ExitState() {

}

ExitState::~ExitState() {

}

void ExitState::init() {

}

void ExitState::handleInput(const sf::Time deltaTime) {

}

void ExitState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	std::cout << "Hello from exiting" << std::endl;
}

void ExitState::render(sf::RenderWindow* window) {

}
