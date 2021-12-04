#pragma once

#include "SolidObject.hpp"

class Box : public SolidObject
{
public:
	Box(std::shared_ptr<Context>& context, int x, int y);

	void update(const sf::Time deltaTime) override;
};
