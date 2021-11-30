#include "State.hpp"

State::State() :
	_objects()
{

}

State::~State() {
	for (Entity* o : _objects) {
		delete o;
	}
	_objects.clear();
}

void State::init() {

}
void State::handleInput(const sf::Time deltaTime) {

}
void State::update(const sf::Time deltaTime) {
	for (Entity* o : _objects) {
		o->update(deltaTime);
	}
}

bool depthLessComparator(Entity* lhs, Entity* rhs) {
	return lhs->getDepth() < rhs->getDepth();
}

void State::render(sf::RenderWindow* window) {
	std::sort(_objects.begin(), _objects.end(), depthLessComparator);
	for (Entity* o : _objects) {
		o->render(window);
	}
}

void State::createObject(Entity* object) {
	_objects.push_back(object);
}

void State::restartObjectsPositions() {
	for (Entity* o : _objects) {
		o->setX(o->XStart());
		o->setY(o->YStart());
	}
}

/*
Game* State::getGame() const {
	return _game;
}
*/