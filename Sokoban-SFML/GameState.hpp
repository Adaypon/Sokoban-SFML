#pragma once

#include "State.hpp"
#include "Entity.hpp"

class GameState : public State
{
private:
	sf::CircleShape _shape;
	Entity _player;
public:
	GameState(Game* game);

	void handleInput(const sf::Time deltaTime) override;
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;
};

