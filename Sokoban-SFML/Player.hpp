#pragma once

#include "Entity.hpp"

class Player : public Entity
{
public:
	Player(std::shared_ptr<Context>& context, int x, int y);
	//~Player();
	
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;
};

