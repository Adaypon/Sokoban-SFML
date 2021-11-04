#pragma once

#include "State.hpp"

class GameState : public State
{
private:
	sf::CircleShape _shape;
public:
	GameState();
	~GameState();

	void handleInput(const sf::Time deltaTime) override;
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;
};

