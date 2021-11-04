#pragma once

#include "State.hpp"

class GameState : public State
{
public:
	GameState();
	~GameState();

	void handleInput() override;
	void update() override;
	void render() override;
};

