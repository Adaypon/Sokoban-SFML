#include "Entity.hpp"

Entity::Entity(std::shared_ptr<Context>& context, const std::string& resource) :
	_context(context)
{
	if (resource != "") {
		_sprite.setTexture((_context->_assets->getTexture(resource)));
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

