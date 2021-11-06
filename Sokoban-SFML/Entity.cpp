#include "Entity.hpp"

Entity::Entity() {
	_shape.setSize(sf::Vector2f(50.f, 50.f));
	_shape.setFillColor(sf::Color::White);
	_movementSpeed = 5.f;
}

Entity::~Entity() {

}

void Entity::move(const sf::Time deltaTime, const float dir_x, const float dir_y) {
	_shape.move(dir_x * _movementSpeed * deltaTime.asSeconds(), dir_y * _movementSpeed * deltaTime.asSeconds());
}

void Entity::update(const sf::Time deltaTime) {
	
}

void Entity::render(sf::RenderWindow* window) {
	window->draw(_shape);
}
