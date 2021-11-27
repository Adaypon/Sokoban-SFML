#pragma once

#include <string>
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

//class State;

struct Context;
//Context* createContextPtr(); // tried to fix C2027


// Base class for all objects
class Entity
{
private:
	std::shared_ptr<Context> _context;
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
	float _imageIndex;
	float _imageSpeed;
	
public:
	Entity(std::shared_ptr<Context>& context, int x, int y, const std::string& resource, int horizontalFrames = 1, int verticalFrames = 1);
	virtual ~Entity();

	virtual void update(const sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);
	sf::Sprite& getSprite();

	enum dirEnum {
		DIR_UP,
		DIR_DOWN,
		DIR_LEFT,
		DIR_RIGHT
	};

	void move(const sf::Time deltaTime, const float dir_x, const float dir_y);

	float X();
	void setX(float x);

	float Y();
	void setY(float y);

	float XStart();
	void setXStart(float x);

	float YStart();
	void setYStart(float y);

	float XPrev();
	void setXPrev(float x);

	float YPrev();
	void setYPrev(float y);

	bool isVisible();
	void setVisible(bool visibleFlag);

	float getDepth();
	void setDepth(float depth);

	// Movement

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
	/*
	template<typename T>
	std::vector<T> getObjectsAtPos(float x, float y);
	*/


};

/*
template<typename T>
inline std::vector<T> Entity::getObjectsAtPos(float x, float y) {
	return createContextPtr()->_states->getCurrentState()->getObjectsAtPos<T>(x, y);
}
*/