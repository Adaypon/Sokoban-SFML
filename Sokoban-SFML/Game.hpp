#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "State.hpp"
#include "GameState.hpp"

class Game {
private:
	sf::RenderWindow* _window;
	sf::Event _event;
	sf::CircleShape _shape;

	float _framesPerSecond;
	unsigned _windowWidth;
	unsigned _windowHeight;
	bool _VSyncFlag;
	std::string _titleBarText;
	sf::Time _timePerFrame; // how much time should elapse before each update and render of one frame
	
	State* _currentState;
	std::array<State*, State::eState::STATE_COUNT> _states;
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

	bool getVSync();
	void setVSync(bool flag);

	sf::Vector2u getResolution();
	void setResolution(unsigned width, unsigned height);

	std::string getTitleBarText();
	void setTitleBarText(const std::string& text);
};