#pragma once

#include "State.hpp"

class LevelSelectState : public State
{
public:
	LevelSelectState(Game* game);
	~LevelSelectState();

	void handleInput(const sf::Time deltaTime) override;
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;
};

