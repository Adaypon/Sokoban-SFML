#include "Player.hpp"
#include "SolidObject.hpp"
#include "Box.hpp"

Player::Player(std::shared_ptr<Context>& context, int x, int y) :
	Entity(context, x, y, "Player", 4, 4)
{
	setMoving(false);
	setDepth(3);
	setMovementSpeed(0),
	setDirection(dirEnum::DIR_DOWN),
	setImageSpeed(0);
	_pushes = 0;

	_pushesText.setFont(_context->_assets->getFont("Main font"));
	_pushesText.setOutlineThickness(2);
	_pushesText.setOutlineColor(sf::Color::Black);
	_pushesText.setPosition(5, 5);
}

void Player::update(const sf::Time deltaTime) {
	if (isVisible()) {
		Entity::update(deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			setMovementSpeed(3.f);
			setImageSpeed(0.175f);
			setMoving(true);
			sf::FloatRect bounds = getSprite().getGlobalBounds();
			_boundsShape.setSize({ bounds.width, bounds.height });
			_boundsShape.setFillColor(sf::Color(0, 255, 0, 128));
			_boundsShape.setPosition(bounds.left, bounds.top);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				setDirection(dirEnum::DIR_LEFT);
				bounds.left -= 1.f;

				_boundsShape.setPosition(bounds.left, bounds.top);
				auto testSprite = getSprite();
				testSprite.setPosition(testSprite.getPosition().x - 2.f, testSprite.getPosition().y);
				std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<SolidObject*>(testSprite);
				if (solids.empty()) {
					move(deltaTime, -1.f, 0.f);
				}
				else {
					_boundsShape.setFillColor(sf::Color(255, 0, 0, 128));
					std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<Box*>(testSprite);
					if (boxes.size() == 1 && solids.size() < 2 && boxes[0]->isAvaliable()) {
						sf::FloatRect nextSolidBounds = boxes[0]->getSprite().getGlobalBounds();
						nextSolidBounds.left -= nextSolidBounds.width;
						std::vector<SolidObject*> nextSolids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
						if (nextSolids.empty()) {
							boxes[0]->setX(boxes[0]->X() - boxes[0]->getSpriteWidth());
							++_pushes;
						}
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				setDirection(dirEnum::DIR_RIGHT);
				bounds.left += 1.f;
								
				_boundsShape.setPosition(bounds.left, bounds.top);
				auto testSprite = getSprite();
				testSprite.setPosition(testSprite.getPosition().x + 2.f, testSprite.getPosition().y);
				std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<SolidObject*>(testSprite);
				if (solids.empty()) {
					move(deltaTime, 1.f, 0.f);
				}
				else {
					_boundsShape.setFillColor(sf::Color(255, 0, 0, 128));
					std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<Box*>(testSprite);
					if (boxes.size() == 1 && solids.size() < 2 && boxes[0]->isAvaliable()) {
						sf::FloatRect nextSolidBounds = boxes[0]->getSprite().getGlobalBounds();
						nextSolidBounds.left += nextSolidBounds.width;
						std::vector<SolidObject*> nextSolids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
						if (nextSolids.empty()) {
							boxes[0]->setX(boxes[0]->X() + boxes[0]->getSpriteWidth());
							++_pushes;
						}
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				setDirection(dirEnum::DIR_UP);
				bounds.top -= 1.f;

				_boundsShape.setPosition(bounds.left, bounds.top);
				auto testSprite = getSprite();
				testSprite.setPosition(testSprite.getPosition().x, testSprite.getPosition().y - 2.f);
				std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<SolidObject*>(testSprite);
				if (solids.empty()) {
					move(deltaTime, 0.f, -1.f);
				}
				else {
					_boundsShape.setFillColor(sf::Color(255, 0, 0, 128));
					std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<Box*>(testSprite);
					if (boxes.size() == 1 && solids.size() < 2 && boxes[0]->isAvaliable()) {
						sf::FloatRect nextSolidBounds = boxes[0]->getSprite().getGlobalBounds();
						nextSolidBounds.top -= nextSolidBounds.height;
						std::vector<SolidObject*> nextSolids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
						if (nextSolids.empty()) {
							boxes[0]->setY(boxes[0]->Y() - boxes[0]->getSpriteHeight());
							++_pushes;
						}
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				setDirection(dirEnum::DIR_DOWN);
				bounds.top += 1.f;

				_boundsShape.setPosition(bounds.left, bounds.top);
				auto testSprite = getSprite();
				testSprite.setPosition(testSprite.getPosition().x, testSprite.getPosition().y + 2.f);
				std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<SolidObject*>(testSprite);
				if (solids.empty()) {
					move(deltaTime, 0.f, 1.f);
				}
				else {
					_boundsShape.setFillColor(sf::Color(255, 0, 0, 128));
					std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<Box*>(testSprite);
					if (boxes.size() == 1 && solids.size() < 2 && boxes[0]->isAvaliable()) {
						sf::FloatRect nextSolidBounds = boxes[0]->getSprite().getGlobalBounds();
						nextSolidBounds.top += nextSolidBounds.height;
						std::vector<SolidObject*> nextSolids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
						if (nextSolids.empty()) {
							boxes[0]->setY(boxes[0]->Y() + boxes[0]->getSpriteHeight());
							++_pushes;
						}
					}
				}
			}
		}
		else {
			_boundsShape.setFillColor(sf::Color(0, 255, 0, 128));
			setImageSpeed(0);
			setMoving(false);

			_boundsShape.setPosition(getSprite().getGlobalBounds().left, getSprite().getGlobalBounds().top);
		}
	}
	
}

void Player::updateSFMLEvents(sf::Event& SFMLEvent) {
	if (SFMLEvent.type == sf::Event::KeyPressed) {
		switch (SFMLEvent.key.code)
		{
		case (sf::Keyboard::R):
		{
			_context->_states->getCurrentState()->restartObjectsPositions();
			_pushes = 0;
			_boundsShape.setPosition(getSprite().getGlobalBounds().left, getSprite().getGlobalBounds().top);
			std::vector<Box*> boxes = _context->_states->getCurrentState()->getAllObjectsOfType<Box*>();
			for (auto box : boxes) {
				box->setAvaliable(true);
			}
		}
			break;
		default:
			break;
		}
	}
}

void Player::render() {
	_pushesText.setString("PUSHES: " + std::to_string(_pushes));
	_context->_window->draw(_pushesText);
	if (isVisible()) {
		int x, y;
		if (isMoving()) {
			x = static_cast<int>(getImageIndex()) % getHorizontalFramesNum();
		}
		else {
			x = 0;
		}

		y = getDirection();
				
		getSprite().setTextureRect(sf::IntRect(x * getSpriteWidth(), y * getSpriteHeight(),
											   getSpriteWidth(), getSpriteHeight()));
		_context->_window->draw(getSprite());
		if (_isBoundsShapeVisible) {
			_context->_window->draw(_boundsShape);
		}
	}
}