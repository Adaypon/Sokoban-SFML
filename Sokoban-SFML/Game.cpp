#include "Game.hpp"

Game::Game() :
    _window(new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!")),
    _shape(100.f),
    _timePerFrame(sf::seconds(1.0f / _framesPerSecond))
{
    
}

Game::~Game() {
    delete _window;
}

/*
void Game::_initWindow() {
    _window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}
*/

void Game::updateSFMLEvents() {
    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _window->close();
        }
    }
}

void Game::update() {
    //updateSFMLEvents();
    _shape.setFillColor(sf::Color::Green);
}

void Game::render() {
    _window->clear();
    _window->draw(_shape);
    _window->display();
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (_window->isOpen()) {
        timeSinceLastUpdate += clock.restart();
        updateSFMLEvents();

        // if the time that has elapsed since last update and render calls
        // is more than time that it's supposed to take to do it
        // then we're going updating stuff
        while (timeSinceLastUpdate > _timePerFrame) {
            timeSinceLastUpdate -= _timePerFrame; // in case of frames dropping
            update();
            updateSFMLEvents();
            //std::cout << "a";
        }
        render(); // keep render not only when it updates
    }
}

float Game::getFPS() {
    return _framesPerSecond;
}

void Game::setFPS(float fps) {
    _framesPerSecond = fps;
    _window->setFramerateLimit(_framesPerSecond);
    _timePerFrame = sf::seconds(1.0f / _framesPerSecond);
}

sf::Vector2u Game::getResolution() {
    return _window->getSize();
}

void Game::setResolution(unsigned width, unsigned height) {
    delete _window;
    _windowWidth = width;
    _windowHeight = height;
    _window = new sf::RenderWindow(sf::VideoMode(_windowWidth, _windowHeight), _titleBarText);
}

std::string Game::getTitleBarText() {
    return _titleBarText;
}

void Game::setTitleBarText(const std::string& text) {
    _titleBarText = text;
    _window->setTitle(_titleBarText);
}
