#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Entity;

class State {
private:
	std::vector<Entity*> _objects;
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

	virtual void init();
	virtual void handleInput(const sf::Time deltaTime);
	virtual void update(const sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);

	// required only for some of the states
	virtual void pause() {};
	virtual void resume() {};


	void createObject(Entity* object);
};