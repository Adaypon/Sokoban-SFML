#pragma once

#include "State.hpp"

class GameState : public State
{
public:
	GameState(Game* game);
	~GameState();

	void handleInput(const sf::Time deltaTime) override;
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;
};

