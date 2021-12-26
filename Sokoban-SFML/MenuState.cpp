#include "MenuState.hpp"
#include "GameState.hpp"
#include "SettingsMenuState.hpp"

MenuState::MenuState(std::shared_ptr<Context>& context) :
	_context(context)
{

}
/*
MenuState::~MenuState() {

}
*/
void MenuState::init() {
	_context->_assets->AddFont("Main font", "assets/fonts/font.ttf");
	_text.setFont(_context->_assets->getFont("Main font"));
	_text.setCharacterSize(42);
	_text.setString("Beta ver. Press Enter to start\nPress ESC to quit\nPress TAB for settings");
	_text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
	_text.setPosition(_context->_window->getView().getSize().x / 2, _context->_window->getView().getSize().y / 2 + 150);

	_context->_assets->AddTexture("Logo", "assets/sprites/logo.png");
	_sprite.setTexture(_context->_assets->getTexture("Logo"));
	_sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);
	_sprite.setPosition(_context->_window->getView().getSize().x / 2, _context->_window->getView().getSize().y / 2);
}

void MenuState::handleInput(const sf::Time deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		_context->_states->addState(std::make_unique<GameState>(_context, 1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
		_context->_states->addState(std::make_unique<SettingsMenuState>(_context));
	}
}

void MenuState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
	std::cout << "Hello from Menu" << std::endl;
}

void MenuState::render() {
	_context->_window->draw(_sprite);
	_context->_window->draw(_text);
}
