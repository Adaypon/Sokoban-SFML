#include "Player.hpp"

Player::Player(std::shared_ptr<Context>& context) :
	Entity(context, "Player")
{

}

/*
Player::~Player() 
{

}
*/

void Player::move(const sf::Time deltaTime, const float dir_x, const float dir_y) {
	std::cout << "testing move() in Player class" << std::endl;
	//getSprite().move(dir_x * _movementSpeed * deltaTime.asSeconds(), dir_y * _movementSpeed * deltaTime.asSeconds());
}

/*
void Player::update(const sf::Time deltaTime) {

}

void Player::render(sf::RenderWindow* window) {

}
*/