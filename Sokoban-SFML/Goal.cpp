#include "Goal.hpp"

Goal::Goal(std::shared_ptr<Context>& context, int x, int y) :
	Entity(context, x, y, "Goal")
{
	setDepth(1);
}
