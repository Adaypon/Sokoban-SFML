#pragma once

#include "State.hpp"

class GameState : public State
{
public:
	GameState();
	~GameState();

	void handleInput() override;
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow& window) override;
};

