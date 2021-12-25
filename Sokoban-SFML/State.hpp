#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Entity;

// Base class of all states
class State {
private:
	std::vector<Entity*> _objects; // The main objects of State
public:
	State();
	virtual ~State();

	// Initialization
	virtual void init();

	/**
	* Handle the events
	* @param deltaTime Elapsed time since the last call
	*/
	virtual void handleInput(const sf::Time deltaTime); 

	/**
	* Updating method
	* @param deltaTime Elapsed time since the last call
	*/
	virtual void update(const sf::Time deltaTime);

	/**
	* Drawing method
	* @param deltaTime Pointer to the window for drawing
	*/
	virtual void render();

	/**
	* pause() and resume() required only for some of the states
	*/

	// Pause the current state
	virtual void pause() {};

	// Start the current state
	virtual void resume() {};


	virtual void updateSFMLEvents(sf::Event& SFMLEvent) {};

	/**
	* Create object
	* @param object pointer of a new entity
	*/
	void createObject(Entity* object);

	// Place all objects to their start position
	void restartObjectsPositions();

	/**
	* Get all objects at the point
	* @param x The x-coordinate of the point
	* @param y The y-coordinate of the point
	* @return Vector of objects
	*/
	template<typename T>
	std::vector<T> getObjectsAtPos(float x, float y);

	/**
	* Get all objects at bounds
	* @param bounds Global bounding rectangle of the entity
	* @return Vector of objects
	*/
	template<typename T>
	std::vector<T> getObjectsAtRect(sf::FloatRect bounds);

	/**
	* Get all objects of a certain type
	* @return Vector of objects
	*/
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
