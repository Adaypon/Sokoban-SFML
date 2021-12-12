#pragma once

#include "Entity.hpp"

class Player : public Entity
{
private:
	int _pushes;
	sf::Text _pushesText;
	sf::RectangleShape _boundsShape;
	bool _isBoundsShapeVisible = false;
public:
	Player(std::shared_ptr<Context>& context, int x, int y);
	//~Player();
	
	void update(const sf::Time deltaTime) override;
	void render() override;
};

