#pragma once

#include "Entity.hpp"

class Player : public Entity
{

private:
	float _movementSpeed = 15.f;

public:
	Player(std::shared_ptr<Context>& context);
	//~Player();
	
	void move(const sf::Time deltaTime, const float dir_x, const float dir_y) override;

	//void update(const sf::Time deltaTime) override;
	//void render(sf::RenderWindow* window) override;
	
};

