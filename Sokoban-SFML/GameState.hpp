#pragma once

#include "State.hpp"

class GameState : public State
{
public:
	GameState();
	~GameState();

	void update() override;
	void render() override;
};

