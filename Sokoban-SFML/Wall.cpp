#include "Wall.hpp"

Wall::Wall(std::shared_ptr<Context>& context, int x, int y) :
	SolidObject(context, x, y, "Wall")
{

}