#pragma once

#include <memory>
#include "State.hpp"
#include "Entity.hpp"
#include "Game.hpp"

struct Context;

class GameState : public State
{
private:
	std::shared_ptr<Context> _context;
	sf::CircleShape _shape;
	Entity _player;
public:
	GameState(std::shared_ptr<Context>& context);
	~GameState();

	void init() override;
	void handleInput(const sf::Time deltaTime) override;
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;
};

