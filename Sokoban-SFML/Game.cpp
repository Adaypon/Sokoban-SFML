#include "Game.hpp"

Game::Game() {
    _initWindow();
    _shape.setRadius(100.f);
    
}

Game::~Game() {
    delete _window;
}

void Game::_initWindow() {
    _window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

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
    while (_window->isOpen()) {
        updateSFMLEvents();
        update();
        render();
    }
}
