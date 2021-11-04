#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class State {
private:
	std::vector<sf::Texture> _textures;

public:
	enum eState {
		Menu,
		Level_select,
		Play,
		Exit,
		STATE_COUNT
	};

	State();
	virtual ~State();

	virtual void handleInput() = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
};

