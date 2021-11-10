#pragma once

#include "State.hpp"

class MenuState : public State
{
public:
	MenuState();
	~MenuState();

	void handleInput(const sf::Time deltaTime) override;
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;
};

