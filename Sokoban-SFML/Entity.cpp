#include "Entity.hpp"

Entity::Entity(std::shared_ptr<Context>& context, int x, int y, const std::string& resource) :
	_context(context),
	_startPos(x, y)
{
	if (resource != "") {
		_sprite.setTexture((_context->_assets->getTexture(resource)));
		_sprite.setPosition(x, y);
	}
}

Entity::~Entity() {

}

void Entity::move(const sf::Time deltaTime, const float dir_x, const float dir_y) {
	_sprite.move(dir_x * _movementSpeed * deltaTime.asSeconds(), dir_y * _movementSpeed * deltaTime.asSeconds());
}

void Entity::update(const sf::Time deltaTime) {
	
}

void Entity::render(sf::RenderWindow* window) {
	//window->draw(_shape);
	_context->_window->draw(_sprite);
}

sf::Sprite& Entity::getSprite() {
	return _sprite;
}

float Entity::X() {
	return _sprite.getPosition().x;
}

void Entity::setX(float x) {
	_sprite.setPosition(x, Y());
}

float Entity::Y() {
	return _sprite.getPosition().y;
}

void Entity::setY(float y) {
	_sprite.setPosition(X(), y);
}

float Entity::XStart() {
	return _startPos.x;
}

void Entity::setXStart(float x) {
	_startPos.x = x;
}

float Entity::YStart() {
	return _startPos.y;
}

void Entity::setYStart(float y) {
	_startPos.y = y;
}