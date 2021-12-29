#include "Box.hpp"
#include "Goal.hpp"

Box::Box(std::shared_ptr<Context>& context, int x, int y) :
	SolidObject(context, x, y, "Box")
{
	setDepth(2);
}

void Box::update(const sf::Time deltaTime) {
	Entity::update(deltaTime);
	std::vector<Goal*> goals = _context->_states->getCurrentState()->getObjectsAtRect<Goal*>(getSprite().getGlobalBounds());
	if (goals.size() == 1) {
		getSprite().setColor(sf::Color::Green);
		_isOnGoal = true;
	}
	else {
		getSprite().setColor(sf::Color::White);
		_isOnGoal = false;
	}
}

bool Box::isOnGoal() {
	return _isOnGoal;
}

bool Box::isAvaliable() {
	if (!isOnGoal()) {
		sf::FloatRect boxBounds = getSprite().getGlobalBounds();
		sf::FloatRect checkBounds = boxBounds;
		checkBounds.left -= checkBounds.width / 2.f;
		checkBounds.top -= checkBounds.height / 2.f;

		std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(checkBounds);
		if (solids.size() == 4) {
			for (SolidObject* solid : solids) {
				std::cout << "Solid: " << solid->X() << " " << solid->Y() << std::endl;
			}
			setAvaliable(false);
			return _isAvaliable;
		}
		else {
			solids.clear();
		}

		checkBounds.left += checkBounds.width;

		solids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(checkBounds);
		if (solids.size() == 4) {
			for (SolidObject* solid : solids) {
				std::cout << "Solid: " << solid->X() << " " << solid->Y() << std::endl;
			}
			setAvaliable(false);
			return _isAvaliable;
		}
		else {
			solids.clear();
		}

		checkBounds.top += checkBounds.height;

		solids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(checkBounds);
		if (solids.size() == 4) {
			for (SolidObject* solid : solids) {
				std::cout << "Solid: " << solid->X() << " " << solid->Y() << std::endl;
			}
			setAvaliable(false);
			return _isAvaliable;
		}
		else {
			solids.clear();
		}

		checkBounds.left -= checkBounds.width;

		solids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(checkBounds);
		if (solids.size() == 4) {
			for (SolidObject* solid : solids) {
				std::cout << "Solid: " << solid->X() << " " << solid->Y() << std::endl;
			}
			setAvaliable(false);
			return _isAvaliable;
		}
		else {
			solids.clear();
		}
	}
	return _isAvaliable;
}

void Box::setAvaliable(bool flag) {
	_isAvaliable = flag;
}