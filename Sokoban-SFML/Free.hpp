#pragma once

#include "Entity.hpp"

class Free : public Entity
{
private:

public:
	Free(std::shared_ptr<Context>& context, int x, int y);
};