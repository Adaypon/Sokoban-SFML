#include "MenuState.hpp"

MenuState::MenuState(std::shared_ptr<Context>& context) :
	_context(context)
{

}

MenuState::~MenuState() {

}

void MenuState::init() {
	_context->_assets->AddFont("Main font", "assets/fonts/font.ttf");
	_text.setFont(_context->_assets->getFont("Main font"));
	_text.setCharacterSize(42);
	_text.setString("Menu State Test");
	_text.setPosition(240, 150);

	_context->_assets->AddTexture("Logo", "assets/sprites/logo.png");
	_sprite.setTexture(_context->_assets->getTexture("Logo"));
}

void MenuState::handleInput(const sf::Time deltaTime) {

}

void MenuState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	std::cout << "Hello from Menu" << std::endl;
}

void MenuState::render(sf::RenderWindow* window) {
	_context->_window->draw(_sprite);
	_context->_window->draw(_text);
}
