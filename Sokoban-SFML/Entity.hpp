#pragma once

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

// Base class for all objects
class Entity
{
private:
	std::shared_ptr<Context> _context;
	sf::Sprite _sprite;
	sf::Vector2f _startPos;
	
public:
	Entity(std::shared_ptr<Context>& context, int x, int y, const std::string& resource);
	virtual ~Entity();

	virtual void update(const sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);
	sf::Sprite& getSprite();

	float X();
	void setX(float x);

	float Y();
	void setY(float y);

	float XStart();
	void setXStart(float x);

	float YStart();
	void setYStart(float y);
};

