#include "PauseGameState.hpp"

PauseGameState::PauseGameState(std::shared_ptr<Context>& context) :
	_context(context)
{

}

void PauseGameState::init() {
	_pauseTitle.setFont(_context->_assets->getFont("Main font"));
	_pauseTitle.setCharacterSize(42);
	_pauseTitle.setString("		  Paused\nPress ESC to return");
	_pauseTitle.setOrigin(_pauseTitle.getLocalBounds().width / 2, _pauseTitle.getLocalBounds().height / 2);
	_pauseTitle.setPosition(_context->_window->getView().getSize().x / 2, _context->_window->getView().getSize().y / 2);
}

void PauseGameState::handleInput(const sf::Time deltaTime) {

}

void PauseGameState::updateSFMLEvents(sf::Event& SFMLEvent) {
	if (SFMLEvent.type == sf::Event::KeyPressed) {
		switch (SFMLEvent.key.code)
		{
		case (sf::Keyboard::Escape):
			_context->_states->popState();
			break;
		default:
			break;
		}
	}
}

void PauseGameState::update(const sf::Time deltaTime) {
	handleInput(deltaTime);
}

void PauseGameState::render() {
	_context->_window->clear(sf::Color(0, 128, 80));
	_context->_window->draw(_pauseTitle);
}