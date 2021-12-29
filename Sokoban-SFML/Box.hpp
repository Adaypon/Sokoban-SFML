#pragma once

#include "SolidObject.hpp"

class Box : public SolidObject
{
private:
	bool _isOnGoal = false;
	bool _isAvaliable = true;
public:
	Box(std::shared_ptr<Context>& context, int x, int y);

	void update(const sf::Time deltaTime) override;

	bool isOnGoal();
	bool isAvaliable();
	void setAvaliable(bool flag);
};
