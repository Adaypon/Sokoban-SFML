#include "Player.hpp"

Player::Player(std::shared_ptr<Context>& context, int x, int y) :
	Entity(context, x, y, "Player")
{

}

/*
Player::~Player() 
{

}
*/

void Player::move(const sf::Time deltaTime, const float dir_x, const float dir_y) {
	getSprite().move(dir_x * _movementSpeed * deltaTime.asSeconds(), dir_y * _movementSpeed * deltaTime.asSeconds());
}


void Player::update(const sf::Time deltaTime) {
	// TODO remake keyboard input cause of too much calls
	
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		setX(XStart());
		setY(YStart());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		setVisible(!isVisible());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
		setDepth(getDepth() + 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
		setDepth(getDepth() - 1);
	}
}
/*
void Player::render(sf::RenderWindow* window) {

}
*/