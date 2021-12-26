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

/*
Player::~Player() 
{

}
*/


void Player::update(const sf::Time deltaTime) {
	// TODO remake keyboard input cause of too much calls
	// TODO moves by one sprite at once
	if (isVisible()) {
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
			_boundsShape.setSize({ bounds.width, bounds.height });
			_boundsShape.setFillColor(sf::Color(0, 255, 0, 128));
			_boundsShape.setPosition(bounds.left, bounds.top);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				setDirection(dirEnum::DIR_LEFT);
				bounds.left -= 1.f;

				_boundsShape.setPosition(bounds.left, bounds.top);
				auto testSprite = getSprite();
				testSprite.setPosition(testSprite.getPosition().x - 2.f, testSprite.getPosition().y);
				std::cout << "Check bounds: " << bounds.left << " " << bounds.top << " w=" << bounds.width << " h=" << bounds.height << std::endl;
				std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<SolidObject*>(testSprite);
				//std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(bounds);
				//std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtPos<SolidObject*>(X() - getSpriteWidth(), Y());
				for (auto solid : solids) {
					std::cout << "\tSolid: " << solid->X() << " " << solid->Y() << std::endl;
				}
				if (solids.empty()) {
					move(deltaTime, -1.f, 0.f);
				}
				else {
					_boundsShape.setFillColor(sf::Color(255, 0, 0, 128));
					std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<Box*>(testSprite);
					//std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsAtRect<Box*>(bounds);
					if (boxes.size() == 1 && solids.size() < 2) {
						// TODO animation of push, after fixing moving function
						/*
						auto boxBounds = boxes[0]->getSprite().getGlobalBounds();
						//std::cout << "\tBox bounds: left=" << boxBounds.left << " top=" << bounds.top << std::endl;
						boxBounds.left -= 1.f;
						boxBounds.width = 1.f;
						//std::cout << "\tBox check bounds: left=" << boxBounds.left << " top=" << bounds.top << std::endl;
						std::vector<SolidObject*> solidsfterBox = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(boxBounds);
						if (solidsfterBox.empty()) {
							boxes[0]->setMovementSpeed(1.f);
							setMovementSpeed(1.f);
							setImageSpeed(0.08f);
							move(deltaTime, -1.f, 0.f);
							boxes[0]->move(deltaTime, -1.f, 0.f);
						}
						*/

						std::cout << "\t\t!!!Solid is box" << std::endl;
						sf::FloatRect nextSolidBounds = boxes[0]->getSprite().getGlobalBounds();
						nextSolidBounds.left -= nextSolidBounds.width;
						std::vector<SolidObject*> nextSolids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
						for (auto solid : nextSolids) {
							std::cout << "\tNext solid: " << solid->X() << " " << solid->Y() << std::endl;
						}
						if (nextSolids.empty()) {
							boxes[0]->setX(boxes[0]->X() - boxes[0]->getSpriteWidth());
							++_pushes;
						}
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				setDirection(dirEnum::DIR_RIGHT);
				bounds.left += 1.f;

				
				
				_boundsShape.setPosition(bounds.left, bounds.top);
				auto testSprite = getSprite();
				testSprite.setPosition(testSprite.getPosition().x + 2.f, testSprite.getPosition().y);

				std::cout << "Check bounds: " << bounds.left << " " << bounds.top << " w=" << bounds.width << " h=" << bounds.height << std::endl;
				std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<SolidObject*>(testSprite);
				//std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(bounds);
				//std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtPos<SolidObject*>(X() + getSpriteWidth(), Y());
				
				
				for (auto solid : solids) {
					std::cout << "\tSolid: " << solid->X() << " " << solid->Y() << std::endl;
				}
				if (solids.empty()) {
					move(deltaTime, 1.f, 0.f);
				}
				else {
					_boundsShape.setFillColor(sf::Color(255, 0, 0, 128));
					std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<Box*>(testSprite);
					//std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsAtRect<Box*>(bounds);
					if (boxes.size() == 1 && solids.size() < 2) {
						std::cout << "\t\t!!!Solid is box" << std::endl;
						/*
						auto boxBounds = boxes[0]->getSprite().getGlobalBounds();
						//std::cout << "\tBox bounds: left=" << boxBounds.left << " top=" << bounds.top << std::endl;
						boxBounds.left += boxBounds.width;
						boxBounds.width = 1.f;
						//std::cout << "\tBox check bounds: left=" << boxBounds.left << " top=" << bounds.top << std::endl;
						std::vector<SolidObject*> solidsfterBox = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(boxBounds);
						if (solidsfterBox.empty()) {
							boxes[0]->setMovementSpeed(1.f);
							setMovementSpeed(1.f);
							setImageSpeed(0.08f);
							move(deltaTime, 1.f, 0.f);
							boxes[0]->move(deltaTime, 1.f, 0.f);
						}
						*/


						sf::FloatRect nextSolidBounds = boxes[0]->getSprite().getGlobalBounds();
						nextSolidBounds.left += nextSolidBounds.width;
						std::vector<SolidObject*> nextSolids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
						for (auto solid : nextSolids) {
							std::cout << "\tNext solid: " << solid->X() << " " << solid->Y() << std::endl;
						}
						if (nextSolids.empty()) {
							boxes[0]->setX(boxes[0]->X() + boxes[0]->getSpriteWidth());
							++_pushes;
						}
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				setDirection(dirEnum::DIR_UP);
				bounds.top -= 1.f;

				_boundsShape.setPosition(bounds.left, bounds.top);
				auto testSprite = getSprite();
				testSprite.setPosition(testSprite.getPosition().x, testSprite.getPosition().y - 2.f);


				std::cout << "Check bounds: " << bounds.left << " " << bounds.top << " w=" << bounds.width << " h=" << bounds.height << std::endl;
				std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<SolidObject*>(testSprite);
				//std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(bounds);
				//std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtPos<SolidObject*>(X(), Y() - getSpriteHeight());
				

				for (auto solid : solids) {
					std::cout << "\tSolid: " << solid->X() << " " << solid->Y() << std::endl;
				}
				if (solids.empty()) {
					move(deltaTime, 0.f, -1.f);
				}
				else {
					_boundsShape.setFillColor(sf::Color(255, 0, 0, 128));
					std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<Box*>(testSprite);
					//std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsAtRect<Box*>(bounds);
					if (boxes.size() == 1 && solids.size() < 2) {
						std::cout << "\t\t!!!Solid is box" << std::endl;
						/*
						auto boxBounds = boxes[0]->getSprite().getGlobalBounds();
						//std::cout << "\tBox bounds: left=" << boxBounds.left << " top=" << bounds.top << std::endl;
						boxBounds.top -= 1;
						boxBounds.height = 1.f;
						//std::cout << "\tBox check bounds: left=" << boxBounds.left << " top=" << bounds.top << std::endl;
						std::vector<SolidObject*> solidsfterBox = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(boxBounds);
						if (solidsfterBox.empty()) {
							boxes[0]->setMovementSpeed(1.f);
							setMovementSpeed(1.f);
							setImageSpeed(0.08f);
							move(deltaTime, 0.f, -1.f);
							boxes[0]->move(deltaTime, 0.f, -1.f);
						}
						*/


						sf::FloatRect nextSolidBounds = boxes[0]->getSprite().getGlobalBounds();
						nextSolidBounds.top -= nextSolidBounds.height;
						std::vector<SolidObject*> nextSolids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
						for (auto solid : nextSolids) {
							std::cout << "\tNext solid: " << solid->X() << " " << solid->Y() << std::endl;
						}
						if (nextSolids.empty()) {
							// TODO slowed down animation of push
							boxes[0]->setY(boxes[0]->Y() - boxes[0]->getSpriteHeight());
							++_pushes;
						}
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				setDirection(dirEnum::DIR_DOWN);
				bounds.top += 1.f;

				_boundsShape.setPosition(bounds.left, bounds.top);
				auto testSprite = getSprite();
				testSprite.setPosition(testSprite.getPosition().x, testSprite.getPosition().y + 2.f);


				std::cout << "Check bounds: " << bounds.left << " " << bounds.top << " w=" << bounds.width << " h=" << bounds.height << std::endl;
				std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<SolidObject*>(testSprite);
				//std::vector<SolidObject*> solids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(bounds);
				//std::vector<SolidObject*> solids = _contextPlayer->_states->getCurrentState()->getObjectsAtPos<SolidObject*>(X(), Y() + getSpriteHeight());
				
				for (auto solid : solids) {
					std::cout << "\tSolid: " << solid->X() << " " << solid->Y() << std::endl;
				}
				if (solids.empty()) {
					move(deltaTime, 0.f, 1.f);
				}
				else {
					_boundsShape.setFillColor(sf::Color(255, 0, 0, 128));
					std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsCollidingAtSprite<Box*>(testSprite);
					//std::vector<Box*> boxes = _context->_states->getCurrentState()->getObjectsAtRect<Box*>(bounds);
					if (boxes.size() == 1 && solids.size() < 2) {
						std::cout << "\t\t!!!Solid is box" << std::endl;
						/*
						auto boxBounds = boxes[0]->getSprite().getGlobalBounds();
						//std::cout << "\tBox bounds: left=" << boxBounds.left << " top=" << bounds.top << std::endl;
						boxBounds.top += boxBounds.height;
						boxBounds.height = 1.f;
						//std::cout << "\tBox check bounds: left=" << boxBounds.left << " top=" << bounds.top << std::endl;
						std::vector<SolidObject*> solidsfterBox = _contextPlayer->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(boxBounds);
						if (solidsfterBox.empty()) {
							boxes[0]->setMovementSpeed(1.f);
							setMovementSpeed(1.f);
							setImageSpeed(0.08f);
							move(deltaTime, 0.f, 1.f);
							boxes[0]->move(deltaTime, 0.f, 1.f);
						}
						*/


						sf::FloatRect nextSolidBounds = boxes[0]->getSprite().getGlobalBounds();
						nextSolidBounds.top += nextSolidBounds.height;
						std::vector<SolidObject*> nextSolids = _context->_states->getCurrentState()->getObjectsAtRect<SolidObject*>(nextSolidBounds);
						for (auto solid : nextSolids) {
							std::cout << "\tNext solid: " << solid->X() << " " << solid->Y() << std::endl;
						}
						if (nextSolids.empty()) {
							// TODO slowed down animation of push
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
		case (sf::Keyboard::Space):
			setVisible(!isVisible());
			break;
		case (sf::Keyboard::Add):
			setDepth(getDepth() + 1);
			break;
		case (sf::Keyboard::Subtract):
			setDepth(getDepth() - 1);
			break;
		case (sf::Keyboard::R):
			_context->_states->getCurrentState()->restartObjectsPositions();
			_pushes = 0;
			_boundsShape.setPosition(getSprite().getGlobalBounds().left, getSprite().getGlobalBounds().top);
			break;
		case (sf::Keyboard::Num0):
			if (_isBoundsShapeVisible) {
				_isBoundsShapeVisible = false;
			}
			else {
				_isBoundsShapeVisible = true;
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
				
		//std::cout << "\t Getting " << x << " " << y << " sprite" << std::endl;
		getSprite().setTextureRect(sf::IntRect(x * getSpriteWidth(), y * getSpriteHeight(),
											   getSpriteWidth(), getSpriteHeight()));
		_context->_window->draw(getSprite());
		if (_isBoundsShapeVisible) {
			_context->_window->draw(_boundsShape);
		}
	}
}
