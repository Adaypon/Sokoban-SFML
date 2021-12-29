#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

class MenuState : public State
{
private:
	std::shared_ptr<Context> _context;
	sf::Text _text;
	sf::Sprite _sprite;
public:
	MenuState(std::shared_ptr<Context>& context);
	//~MenuState();

	void init() override;
	void handleInput(const sf::Time deltaTime) override;
	void updateSFMLEvents(sf::Event& SFMLEvent) override;
	void update(const sf::Time deltaTime) override;
	void render() override;
};
