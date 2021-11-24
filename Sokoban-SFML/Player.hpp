#pragma once

#include "Entity.hpp"

class Player : public Entity
{

private:
	float _movementSpeed = 3.f;
	enum _dirEnum {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	int _direction = _dirEnum::DOWN;
	bool _isMoving;
	std::shared_ptr<Context> _contextPlayer; // ךמסעûûûûûûכü

public:
	Player(std::shared_ptr<Context>& context, int x, int y);
	//~Player();
	
	void move(const sf::Time deltaTime, const float dir_x, const float dir_y);

	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;
	
};

