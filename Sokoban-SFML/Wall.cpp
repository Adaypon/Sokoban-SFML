#include "Wall.hpp"

Wall::Wall(std::shared_ptr<Context>& context, int x, int y) :
	Entity(context, x, y, "Wall")
{

}
