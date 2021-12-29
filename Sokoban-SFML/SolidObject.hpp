#pragma once

#include "Entity.hpp"

// Placeholder for solid objects (wall, box)
class SolidObject : public Entity
{
private:

public:
	SolidObject(std::shared_ptr<Context>& context, int x, int y, const std::string& resource, int horizontalFrames = 1, int verticalFrames = 1);
};