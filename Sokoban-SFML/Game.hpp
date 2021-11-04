#pragma once

#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game {
private:
	sf::RenderWindow* _window;
	sf::Event _event;
	sf::CircleShape _shape;

	float _framesPerSecond;
	unsigned _windowWidth;
	unsigned _windowHeight;
	std::string _titleBarText;
	sf::Time _timePerFrame; // how much time should elapse before each update and render of one frame
	
	//void _initWindow();

public:
	Game();
	~Game();

	void updateSFMLEvents();
	void update();
	void render();
	void run();

	float getFPS();
	void setFPS(float fps);

	sf::Vector2u getResolution();
	void setResolution(unsigned width, unsigned height);

	std::string getTitleBarText();
	void setTitleBarText(const std::string& text);
};