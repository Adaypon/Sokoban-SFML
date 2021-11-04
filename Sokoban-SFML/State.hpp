#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class State {
private:
	std::vector<sf::Texture> _textures;

public:
	State();
	virtual ~State();

	virtual void update() = 0;
	virtual void render() = 0;
};

