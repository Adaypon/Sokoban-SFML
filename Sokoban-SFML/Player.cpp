#include "Player.hpp"

Player::Player(std::shared_ptr<Context>& context, int x, int y) :
	Entity(context, x, y, "Player", 4, 4)
{
	_contextPlayer = context;
	_isMoving = false;
	setDepth(1);
	setImageSpeed(0);
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
	
	Entity::update(deltaTime);

	// TODO try switch-case 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		setImageSpeed(0.175f);
		_isMoving = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			_direction = _dirEnum::LEFT;
			move(deltaTime, -1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			_direction = _dirEnum::RIGHT;
			move(deltaTime, 1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			_direction = _dirEnum::UP;
			move(deltaTime, 0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			_direction = _dirEnum::DOWN;
			move(deltaTime, 0.f, 1.f);
		}
	}
	else {
		setImageSpeed(0);
		_isMoving = false;
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

void Player::render(sf::RenderWindow* window) {
	//window->draw(_shape);
	if (isVisible()) {
		int x, y;
		if (_isMoving) {
			x = static_cast<int>(getImageIndex()) % 4; // TODO remove hardcode
		}
		else {
			x = 0;
		}

		y = _direction;
		//int y = static_cast<int>(getImageIndex()) / 3;
		
		//std::cout << "\t Getting " << x << " " << y << " sprite" << std::endl;
		getSprite().setTextureRect(sf::IntRect(x * getSpriteWidth(), y * getSpriteHeight(),
											   getSpriteWidth(), getSpriteHeight()));
		_contextPlayer->_window->draw(getSprite());
	}
}
