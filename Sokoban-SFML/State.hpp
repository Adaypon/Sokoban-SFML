#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

//class Game;

class State {
private:
	std::vector<sf::Texture> _textures;
	
	// each state has a local pointer on the Game instance
	// because they are responsible for changing the state
	// Game* _game;

public:
	enum eState {
		Menu,
		LevelSelect,
		Play,
		Exit,
		STATE_COUNT
	};

	State();
	virtual ~State();

	// Game* getGame() const;

	virtual void handleInput(const sf::Time deltaTime) = 0;
	virtual void update(const sf::Time deltaTime) = 0;
	virtual void render(sf::RenderWindow* window) = 0;
};