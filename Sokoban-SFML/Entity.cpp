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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		move(deltaTime, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move(deltaTime, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		move(deltaTime, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		move(deltaTime, 0.f, 1.f);
	}
}

void Entity::render(sf::RenderWindow* window) {
	window->draw(_shape);
}
