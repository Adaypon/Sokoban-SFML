#pragma once

#include "State.hpp"

class ExitState : public State
{
public:
	ExitState();
	~ExitState();

	void handleInput(const sf::Time deltaTime) override;
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;
};

