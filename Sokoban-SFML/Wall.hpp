#pragma once

#include "SolidObject.hpp"

class Wall : public SolidObject
{
private:

public:
	Wall(std::shared_ptr<Context>& context, int x, int y);
};