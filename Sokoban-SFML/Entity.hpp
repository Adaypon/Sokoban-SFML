#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
private:

protected:
	sf::RectangleShape _shape; // placeholder
	float _movementSpeed;
public:
	Entity();
	virtual ~Entity();

	virtual void move(const sf::Time deltaTime, const float dir_x, const float dir_y);

	virtual void update(const sf::Time deltaTime);
	virtual void render(sf::RenderTarget* target);
};

