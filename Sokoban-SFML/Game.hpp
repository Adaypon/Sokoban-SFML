#pragma once

#include <memory>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "StateManager.hpp"
#include "SceneManager.hpp"

class StateManager;

// Data of states, assets and window
struct Context {
	std::unique_ptr<StateManager> _states;
	std::unique_ptr<SceneManager> _assets;
	std::unique_ptr<sf::RenderWindow> _window;
	
	Context() {
		_states = std::make_unique<StateManager>();
		_assets = std::make_unique<SceneManager>();
		_window = std::make_unique<sf::RenderWindow>();
	}
};

class Game {
private:
	//sf::RenderWindow* _window;
	std::shared_ptr<Context> _context;

	sf::Event _event;

	float _framesPerSecond;
	unsigned _windowWidth;
	unsigned _windowHeight;
	bool _VSyncFlag;
	std::string _titleBarText;
	sf::Time _timePerFrame; // How much time should elapse before each update and render of one frame
	
	// Initialization of states
	void _initStates();

	// Initialization of window
	void _initWindow();

public:
	Game();
	~Game();

	void updateSFMLEvents();
	void update();
	void render();
	void run();

	// Get render window pointer
	sf::RenderWindow* getWindow() const;

	// Get goal FPS
	float getFPS() const;
	
	// Set goal FPS
	void setFPS(float fps);


	// Get VSync flag
	bool getVSync() const; 
	
	// Set VSync flag
	void setVSync(bool flag);


	// Get window resolution
	sf::Vector2u getResolution() const; 
	
	// Set window resolution
	void setResolution(unsigned width, unsigned height); 


	// Get title bar text
	std::string getTitleBarText() const;

	// Set title bar text
	void setTitleBarText(const std::string& text);
};