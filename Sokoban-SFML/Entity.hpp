#pragma once

#include <string>
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

struct Context;

// Base class for all objects
class Entity
{
protected:
	std::shared_ptr<Context> _context;
private:
	sf::Sprite _sprite;
	sf::Vector2f _startPos;
	sf::Vector2f _prevPos;
	bool _visible;
	float _depth;
	
	float _movementSpeed;
	int _direction;
	bool _isMoving;

	int _horizontalFrames;
	int _verticalFrames;
	float _imageIndex; // Index of image in tileset 
	float _imageSpeed; // Speed of image changing
	
public:
	Entity(std::shared_ptr<Context>& context, int x, int y, const std::string& resource, int horizontalFrames = 1, int verticalFrames = 1);
	virtual ~Entity();

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
	
	// Get sprite of entity
	sf::Sprite& getSprite();

	enum dirEnum {
		DIR_UP,
		DIR_DOWN,
		DIR_LEFT,
		DIR_RIGHT
	};

	/**
	* Move entity
	* @param deltaTime
	* @param dir_x X-Direction
	* @param dir_y Y-Direction
	*/
	void move(const sf::Time deltaTime, const float dir_x, const float dir_y);

	// Get x coordinate
	float X();

	// Set x coordinate
	void setX(float x);


	// Get y coordinate
	float Y();

	// Set y coordinate
	void setY(float y);


	// Get start x coordinate
	float XStart();

	// Set start x coordinate
	void setXStart(float x);


	// Get start y coordinate
	float YStart();

	// Set start y coordinate
	void setYStart(float y);


	// Get previous x coordinate
	float XPrev();

	// Set previous x coordinate
	void setXPrev(float x);


	// Get previous y coordinate
	float YPrev();

	// Set previous y coordinate
	void setYPrev(float y);


	// Checking of entity displaying 
	bool isVisible();

	// Set visibility
	void setVisible(bool visibleFlag);


	// Get depth layer
	float getDepth();

	// Set depth layer
	void setDepth(float depth);

	
	/**
	* Movement Section
	*/

	float getMovementSpeed();
	void setMovementSpeed(float speed);

	int getDirection();
	void setDirection(int dir);

	bool isMoving();
	void setMoving(bool flag);

	// Animation

	float getImageIndex();
	void setImageIndex(float value);

	float getImageSpeed();
	void setImageSpeed(float value);

	int getSpriteWidth();
	int getSpriteHeight();

	bool isPointWithinSpriteBounds(float x, float y);

	int getHorizontalFramesNum();
	int getVerticalFramesNum();
};