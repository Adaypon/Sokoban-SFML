#include "MenuState.hpp"

MenuState::MenuState() {

}

MenuState::~MenuState() {

}

void MenuState::handleInput(const sf::Time deltaTime) {

}

void MenuState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	std::cout << "Hello from Menu" << std::endl;
}

void MenuState::render(sf::RenderWindow* window) {

}
