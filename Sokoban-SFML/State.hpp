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
	virtual void update() = 0;
	virtual void render() = 0;
};

