#pragma once

#include <string>
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

struct Context;

/**
	Base class for all objects
*/
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


	virtual void updateSFMLEvents(sf::Event& SFMLEvent) {};

	/**
		Drawing method
	*/
	virtual void render();
	
	/**
		Get sprite of entity
	*/
	sf::Sprite& getSprite();

	/**
		Enum of entity directions
	*/
	enum dirEnum {
		DIR_UP,
		DIR_DOWN,
		DIR_LEFT,
		DIR_RIGHT
	};

	/**
	* Move entity
	* @param deltaTime update time
	* @param dir_x X-Direction
	* @param dir_y Y-Direction
	*/
	void move(const sf::Time deltaTime, const float dir_x, const float dir_y);

	/**
		Get x coordinate
		@return x coordinate
	*/
	float X();

	/**
		Set x coordinate
		@param x new x coordinate
	*/
	void setX(float x);


	/**
		Get y coordinate
		@return y coordinate
	*/
	float Y();

	/**
		Set y coordinate
		@param y new y coordinate
	*/
	void setY(float y);


	/**
		Get start x coordinate
		@return start x coordinate
	*/
	float XStart();

	/**
		Set start x coordinate
		@param x new start x coordinate
	*/
	void setXStart(float x);


	/**
		Get start y coordinate
		@return start y coordinate
	*/
	float YStart();

	/**
		Set start y coordinate
		@param y new start y coordinate
	*/
	void setYStart(float y);


	/**
		Get previous x coordinate
		@return previous x coordinate
	*/
	float XPrev();

	/**
		Set previous x coordinate
		@param x new previous x coordinate
	*/
	void setXPrev(float x);


	/**
		Get previous y coordinate
		@return previous y coordinate
	*/
	float YPrev();

	/**
		Set previous y coordinate
		@param y new previous y coordinate
	*/
	void setYPrev(float y);


	/**
		Check of entity displaying
	*/
	bool isVisible();

	/**
		Set visibility of entity
		@param visibleFlag boolean of visibility
	*/
	void setVisible(bool visibleFlag);


	/**
		Get depth layer
		@return depth value
	*/
	float getDepth();

	/**
		Set depth layer
		@param depth new depth value
	*/
	void setDepth(float depth);

	
	/**
	* Movement Section
	*/

	/**
		Get speed of entity
		@return speed value
	*/
	float getMovementSpeed();

	/**
		Set speed of entity
		@param speed new speed value
	*/
	void setMovementSpeed(float speed);


	/**
		Get current direction of entity
		@return current direction (dirEnum value)
	*/
	int getDirection();

	/**
		Set current direction of entity
		@param dir the dirEnum value
	*/
	void setDirection(int dir);

	/**
		Check of moving entity
	*/
	bool isMoving();

	/**
		Set moving boolean
		@param flag new boolean value of moving
	*/
	void setMoving(bool flag);

	/**
	* Animation Section
	*/

	/**
		Get current index of image in tileset
		@return image index
	*/
	float getImageIndex();

	/**
		Set index of image in tileset
		@param value new index
	*/
	void setImageIndex(float value);

	/**
		Get current speed of image changing
		@return speed value
	*/
	float getImageSpeed();

	/**
		Set speed of image changing
		@param value new speed value
	*/
	void setImageSpeed(float value);


	/**
		Get width of the entity sprite
		@return sprite width
	*/
	int getSpriteWidth();

	/**
		Get height of the entity sprite
		@return sprite height
	*/
	int getSpriteHeight();

	/**
		Check if point within the bounds of the entity sprite
	*/
	bool isPointWithinSpriteBounds(float x, float y);

	/**
		Get number of horizontal frames
		@return number of horizontal frames
	*/
	int getHorizontalFramesNum();

	/**
		Get number of vertical frames
		@return number of vertical frames
	*/
	int getVerticalFramesNum();
};