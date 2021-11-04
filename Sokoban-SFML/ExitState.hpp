#pragma once

#include "State.hpp"

class ExitState : public State
{
public:
	ExitState(Game* game);
	~ExitState();

	void handleInput() override;
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;
};

