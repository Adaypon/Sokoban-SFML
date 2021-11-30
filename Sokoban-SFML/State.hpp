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

	void restartObjectsPositions();

	template<typename T>
	std::vector<T> getObjectsAtPos(float x, float y);

	template<typename T>
	std::vector<T> getObjectsAtRect(sf::FloatRect bounds);

	template<typename T>
	std::vector<T> getAllObjectsOfType();

};

template<typename T>
inline std::vector<T> State::getObjectsAtPos(float x, float y) {
	std::vector<T> resultObjects;
	for (Entity* o : _objects) {
		T cast = dynamic_cast<T>(o);
		if (cast != nullptr) {
			if (o->isPointWithinSpriteBounds(x, y)) {
				resultObjects.push_back(cast);
			}
		}
	}
	return resultObjects;
}

template<typename T>
inline std::vector<T> State::getObjectsAtRect(sf::FloatRect bounds) {
	std::vector<T> resultObjects;
	for (Entity* o : _objects) {
		T cast = dynamic_cast<T>(o);
		if (cast != nullptr) {
			if (o->getSprite().getGlobalBounds().intersects(bounds)) {
				resultObjects.push_back(cast);
			}
		}
	}
	return resultObjects;
}

template<typename T>
inline std::vector<T> State::getAllObjectsOfType() {
	std::vector<T> resultObjects;
	for (Entity* o : _objects) {
		T cast = dynamic_cast<T>(o);
		if (cast != nullptr) {
			resultObjects.push_back(cast);
		}
	}
	return resultObjects;
}
