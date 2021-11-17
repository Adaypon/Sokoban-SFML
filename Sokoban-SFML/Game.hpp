#pragma once

#include <memory>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "StateManager.hpp"
#include "SceneManager.hpp"

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
	sf::Time _timePerFrame; // how much time should elapse before each update and render of one frame
	
	// TODO remove _currentState and _states as they're in StateManager
	//State* _currentState;
	//std::array<State*, State::eState::STATE_COUNT> _states;
	void _initStates();
	void _initWindow();

public:
	Game();
	~Game();

	void updateSFMLEvents();
	void update();
	void render();
	void run();

	// TODO remove this methods as they're in StateManager
	//State* getCurrentState() const;
	//void changeState(State::eState state);

	sf::RenderWindow* getWindow() const;

	float getFPS() const;
	void setFPS(float fps);

	bool getVSync() const;
	void setVSync(bool flag);

	sf::Vector2u getResolution() const;
	void setResolution(unsigned width, unsigned height);

	std::string getTitleBarText() const;
	void setTitleBarText(const std::string& text);
};