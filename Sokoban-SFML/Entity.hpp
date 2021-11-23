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
	float _movementSpeed = 15.f; // TODO remove later
public:
	Entity(std::shared_ptr<Context>& context, int x, int y, const std::string& resource);
	virtual ~Entity();

	virtual void move(const sf::Time deltaTime, const float dir_x, const float dir_y); // TODO remove later

	virtual void update(const sf::Time deltaTime);
	virtual void render(sf::RenderWindow* window);
	sf::Sprite& getSprite();

	float X();
	void setX(float x);

	float Y();
	void setY(float y);
};

