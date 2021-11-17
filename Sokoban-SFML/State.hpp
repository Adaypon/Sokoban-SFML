#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class State {
public:
	enum eState {
		Menu,
		LevelSelect,
		Play,
		Exit,
		STATE_COUNT
	};

	State();
	virtual ~State();

	virtual void init() = 0;
	virtual void handleInput(const sf::Time deltaTime) = 0;
	virtual void update(const sf::Time deltaTime) = 0;
	virtual void render(sf::RenderWindow* window) = 0;

	// required only for some of the states
	virtual void pause() {};
	virtual void resume() {};
};