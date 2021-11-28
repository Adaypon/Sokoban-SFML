#include "Box.hpp"
#include "Goal.hpp"

Box::Box(std::shared_ptr<Context>& context, int x, int y) :
	SolidObject(context, x, y, "Box")
{
	_contextBox = context;
	setDepth(2);
}

void Box::update(const sf::Time deltaTime) {
	Entity::update(deltaTime);

	std::vector<Goal*> goals = _contextBox->_states->getCurrentState()->getObjectsAtRect<Goal*>(getSprite().getGlobalBounds());
	if (goals.size() == 1) {
		getSprite().setColor(sf::Color::Green);
	}
	else {
		getSprite().setColor(sf::Color::White);
	}
}
