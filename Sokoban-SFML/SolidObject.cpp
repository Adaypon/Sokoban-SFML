#include "SolidObject.hpp"

SolidObject::SolidObject(std::shared_ptr<Context>& context, int x, int y, const std::string& resource, int horizontalFrames, int verticalFrames) :
	Entity(context, x, y, resource, horizontalFrames, verticalFrames)
{

}
