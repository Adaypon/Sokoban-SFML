#pragma once

#include "SolidObject.hpp"

class Box : public SolidObject
{
private:

public:
	Box(std::shared_ptr<Context>& context, int x, int y);
};
