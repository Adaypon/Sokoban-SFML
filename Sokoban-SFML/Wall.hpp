#pragma once

#include "Entity.hpp"

class Wall : public Entity
{
private:

public:
	Wall(std::shared_ptr<Context>& context, int x, int y);
};
