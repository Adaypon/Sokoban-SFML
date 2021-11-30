#include "Entity.hpp"

Entity::Entity(std::shared_ptr<Context>& context, int x, int y, const std::string& resource, int horizontalFrames, int verticalFrames) :
	_context(context),
	_startPos(x, y),
	_prevPos(x, y),
	_visible(true),
	_depth(0),
	_horizontalFrames(horizontalFrames),
	_verticalFrames(verticalFrames),
	_imageIndex(0),
	_imageSpeed(0)
{
	if (resource != "") {
		_sprite.setTexture((_context->_assets->getTexture(resource)));
		_sprite.setPosition(x, y);
	}
}

Entity::~Entity() {

}

void Entity::update(const sf::Time deltaTime) {
	// Animantion component
	setImageIndex(getImageIndex() + getImageSpeed());
}

void Entity::render(sf::RenderWindow* window) {
	//window->draw(_shape);
	if (isVisible()) {
		int x = static_cast<int>(getImageIndex()) % _horizontalFrames;
		int y = static_cast<int>(getImageIndex()) / _horizontalFrames;
		//std::cout << "\t Getting " << x << " " << y << " sprite" << std::endl;
		_sprite.setTextureRect(sf::IntRect(x * getSpriteWidth(), y * getSpriteHeight(), 
								getSpriteWidth(), getSpriteHeight()));
		_context->_window->draw(_sprite);
	}
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

void Entity::move(const sf::Time deltaTime, const float dir_x, const float dir_y) {
	_sprite.move(dir_x * _movementSpeed * deltaTime.asSeconds(), dir_y * _movementSpeed * deltaTime.asSeconds());
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

float Entity::XPrev() {
	return _prevPos.x;
}

void Entity::setXPrev(float x) {
	_prevPos.x = x;
}

float Entity::YPrev() {
	return _prevPos.y;
}

void Entity::setYPrev(float y) {
	_prevPos.y = y;
}

bool Entity::isVisible() {
	return _visible;
}

void Entity::setVisible(bool visibleFlag) {
	_visible = visibleFlag;
}

float Entity::getDepth() {
	return _depth;
}

void Entity::setDepth(float depth) {
	_depth = depth;
}

float Entity::getImageIndex() {
	return _imageIndex;
}

void Entity::setImageIndex(float value) {
	value = fmod(value, _horizontalFrames * _verticalFrames);
	
	// check for negative value
	if (value < 0) {
		value += _horizontalFrames * _verticalFrames;
	}

	_imageIndex = value;
}

float Entity::getMovementSpeed() {
	return _movementSpeed;
}

void Entity::setMovementSpeed(float speed) {
	_movementSpeed = speed;
}

float Entity::getImageSpeed() {
	return _imageSpeed;
}

void Entity::setImageSpeed(float value) {
	_imageSpeed = value;
}

int Entity::getDirection() {
	return _direction;
}

void Entity::setDirection(int dir) {
	_direction = dir;
}

int Entity::getSpriteWidth() {
	return _sprite.getTexture()->getSize().x / _horizontalFrames;
}

int Entity::getSpriteHeight() {
	return _sprite.getTexture()->getSize().y / _verticalFrames;
}

bool Entity::isMoving() {
	return _isMoving;
}

void Entity::setMoving(bool flag) {
	_isMoving = flag;
}

bool Entity::isPointWithinSpriteBounds(float x, float y) {
	//std::cout << "\t\t !checking" << x << " " << y << std::endl;
	if (x >= X() && x < (X() + getSpriteWidth()) &&
		y >= Y() && y < (Y() + getSpriteHeight())) {
		//std::cout << X() << "<= x=" << x << " < " << X() + getSpriteWidth() << std::endl;
		//std::cout << Y() << "<= y=" << y << " < " << Y() + getSpriteHeight() << std::endl;
		//std::getchar();
		return true;
	}
	return false;
}

int Entity::getHorizontalFramesNum() {
	return _horizontalFrames;
}

int Entity::getVerticalFramesNum() {
	return _verticalFrames;
}
