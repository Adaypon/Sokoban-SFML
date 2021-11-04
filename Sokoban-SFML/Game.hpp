#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game {
private:
	static float _framesPerSecond;

	sf::RenderWindow* _window;
	sf::Event _event;
	sf::CircleShape _shape;

	// how much time should elapse 
	// before each update and render of one frame
	sf::Time _timePerFrame;
	
	//void _initWindow();

public:
	Game();
	~Game();

	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

