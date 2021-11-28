#include "Player.hpp"
#include "SolidObject.hpp"
#include "Box.hpp"

Player::Player(std::shared_ptr<Context>& context, int x, int y) :
	Entity(context, x, y, "Player", 4, 4)
{
	_contextPlayer = context;
	setMoving(false);
	setDepth(3);
	setMovementSpeed(0),
	setDirection(dirEnum::DIR_DOWN),
	setImageSpeed(0);
}

/*
Player::~Player() 
{

}
*/

/*
void Player::move(const sf::Time deltaTime, const float dir_x, const float dir_y) {
	getSprite().move(dir_x * _movementSpeed * deltaTime.asSeconds(), dir_y * _movementSpeed * deltaTime.asSeconds());
}
*/

void Player::update(const sf::Time deltaTime) {
	// TODO remake keyboard input cause of too much calls
	// TODO moves by one sprite at once
	
	Entity::update(deltaTime);
	std::cout << "Player: " << X() << " " << Y() << std::endl;
	// TODO try switch-case 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		setMovementSpeed(3.f);
		setImageSpeed(0.175f);
		setMoving(true);
		sf::FloatRect bounds = getSprite().getGlobalBounds();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			setDirection(dirEnum::DIR_LEFT);
			bounds.left -= 1.f;
			std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(bounds);
			//std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtPos<SolidObject*>(X() - getSpriteWidth(), Y());
			for (auto solid : solids) {
				std::cout << "\tSolid: " << solid->X() << " " << solid->Y() << std::endl;
			}
			if (solids.empty()) {
				move(deltaTime, -1.f, 0.f);
			}
			else {
				std::vector<Box*> boxes = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<Box*>(bounds);
				if (boxes.size() == 1) {
					std::cout << "\t\t!!!Solid is box" << std::endl;
						sf::FloatRect nextSolidBounds = getSprite().getGlobalBounds();
					nextSolidBounds.left -= getSpriteWidth() * 2;
					std::vector<SolidObject*> nextSolids = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
					for (auto solid : nextSolids) {
						std::cout << "\tNext solid: " << solid->X() << " " << solid->Y() << std::endl;
					}
					if (nextSolids.empty()) {
						// TODO slowed down animation of push
						boxes[0]->setX(boxes[0]->X() - boxes[0]->getSpriteWidth());
					}					
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			setDirection(dirEnum::DIR_RIGHT);
			bounds.width += 1.f;
			std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(bounds);
			//std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtPos<SolidObject*>(X() + getSpriteWidth(), Y());
			for (auto solid : solids) {
				std::cout << "\tSolid: " << solid->X() << " " << solid->Y() << std::endl;
			}
			if (solids.empty()) {
				move(deltaTime, 1.f, 0.f);
			}
			else {
				std::vector<Box*> boxes = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<Box*>(bounds);
				if (boxes.size() == 1) {
					sf::FloatRect nextSolidBounds = getSprite().getGlobalBounds();
					nextSolidBounds.left += getSpriteWidth() * 2;
					std::vector<SolidObject*> nextSolids = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
					for (auto solid : nextSolids) {
						std::cout << "\tNext solid: " << solid->X() << " " << solid->Y() << std::endl;
					}
					if (nextSolids.empty()) {
						// TODO slowed down animation of push
						boxes[0]->setX(boxes[0]->X() + boxes[0]->getSpriteWidth());
					}
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			setDirection(dirEnum::DIR_UP);
			bounds.top -= 1.f;
			std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(bounds);
			//std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtPos<SolidObject*>(X(), Y() - getSpriteHeight());
			for (auto solid : solids) {
				std::cout << "\tSolid: " << solid->X() << " " << solid->Y() << std::endl;
			}
			if (solids.empty()) {
				move(deltaTime, 0.f, -1.f);
			}
			else {
				std::vector<Box*> boxes = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<Box*>(bounds);
				if (boxes.size() == 1) {
					sf::FloatRect nextSolidBounds = getSprite().getGlobalBounds();
					nextSolidBounds.top -= getSpriteWidth() * 2;
					std::vector<SolidObject*> nextSolids = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
					for (auto solid : nextSolids) {
						std::cout << "\tNext solid: " << solid->X() << " " << solid->Y() << std::endl;
					}
					if (nextSolids.empty()) {
						// TODO slowed down animation of push
						boxes[0]->setY(boxes[0]->Y() - boxes[0]->getSpriteHeight());
					}
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			setDirection(dirEnum::DIR_DOWN);
			bounds.height += 1.f;
			std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(bounds);
			//std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtPos<SolidObject*>(X(), Y() + getSpriteHeight());
			for (auto solid : solids) {
				std::cout << "\tSolid: " << solid->X() << " " << solid->Y() << std::endl;
			}
			if (solids.empty()) {
				move(deltaTime, 0.f, 1.f);
			}
			else {
				std::vector<Box*> boxes = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<Box*>(bounds);
				if (boxes.size() == 1) {
					sf::FloatRect nextSolidBounds = getSprite().getGlobalBounds();
					nextSolidBounds.top += getSpriteWidth() * 2;
					std::vector<SolidObject*> nextSolids = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
					for (auto solid : nextSolids) {
						std::cout << "\tNext solid: " << solid->X() << " " << solid->Y() << std::endl;
					}
					if (nextSolids.empty()) {
						// TODO slowed down animation of push
						boxes[0]->setY(boxes[0]->Y() + boxes[0]->getSpriteHeight());
					}
				}
			}
		}
	}
	else {
		setImageSpeed(0);
		setMoving(false);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		setDirection(DIR_DOWN);
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
		if (isMoving()) {
			x = static_cast<int>(getImageIndex()) % 4; // TODO remove hardcode
		}
		else {
			x = 0;
		}

		y = getDirection();
		//int y = static_cast<int>(getImageIndex()) / 3;
		
		//std::cout << "\t Getting " << x << " " << y << " sprite" << std::endl;
		getSprite().setTextureRect(sf::IntRect(x * getSpriteWidth(), y * getSpriteHeight(),
											   getSpriteWidth(), getSpriteHeight()));
		_contextPlayer->_window->draw(getSprite());
	}
}
