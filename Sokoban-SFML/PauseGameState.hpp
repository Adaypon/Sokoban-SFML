#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

class PauseGameState : public State
{
private:
	std::shared_ptr<Context> _context;
	sf::Text _pauseTitle;
public:
	PauseGameState(std::shared_ptr<Context>& context);

	void init() override;
	void handleInput(const sf::Time deltaTime) override;
	void updateSFMLEvents(sf::Event& SFMLEvent) override;
	void update(const sf::Time deltaTime) override;
	void render() override;
};