#include "Game.hpp"

Game::Game() :
    _context(std::make_shared<Context>()),
    _framesPerSecond(60.0f),
    _windowWidth(1280),
    _windowHeight(720),
    _titleBarText("Sokoban"),
    _VSyncFlag(true),
    _timePerFrame(sf::seconds(1.0f / _framesPerSecond))
{
    _initWindow();
    _initStates();
    //changeState(State::eState::Play);
}

Game::~Game() {
    //delete _window;
    /*
    _context->_window.reset();
    for (State* state : _states) {
        delete state;
    }
    */
}

void Game::_initWindow() {
    _context->_window->create(sf::VideoMode(_windowWidth, _windowHeight), _titleBarText);
    //_window = new sf::RenderWindow(sf::VideoMode(_windowWidth, _windowHeight), _titleBarText);
    _context->_window->setFramerateLimit(_framesPerSecond);
    _context->_window->setVerticalSyncEnabled(_VSyncFlag);
}

void Game::_initStates() {
    /*
    _states[State::eState::Menu] = new MenuState();
    _states[State::eState::LevelSelect] = new LevelSelectState();
    _states[State::eState::Play] = new GameState();
    _states[State::eState::Exit] = new ExitState();
    */

    _context->_states->addState(std::make_unique<MenuState>(_context));
    _context->_states->changeState();
}


void Game::updateSFMLEvents() {
    while (_context->_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _context->_window->close();
        }
    }
}

void Game::update() {
    //updateSFMLEvents();
    
    //_currentState->update(sf::seconds(1));
    _context->_states->getCurrentState()->update(sf::seconds(1));
}

void Game::render() {
    _context->_window->clear();
    //_window->draw(_shape);
    
    //_currentState->render(getWindow());
    _context->_states->getCurrentState()->render(getWindow());

    _context->_window->display();
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (_context->_window->isOpen()) {
        timeSinceLastUpdate += clock.restart();
        updateSFMLEvents();

        // if the time that has elapsed since last update and render calls
        // is more than time that it's supposed to take to do it
        // then we're going updating stuff
        while (timeSinceLastUpdate > _timePerFrame) {
            timeSinceLastUpdate -= _timePerFrame; // in case of frames dropping
            /** TODO
            * - process state change
            * - handle input in current state
            * - call update
            * - call draw
            */
            _context->_states->changeState();
            
            update();
            updateSFMLEvents();
            //std::cout << "a";
        }
        render(); // keep render not only when it updates
    }
}
/*
State* Game::getCurrentState() const {
    return _currentState;
}

void Game::changeState(State::eState state) {
    _currentState = _states[state];
}
*/

sf::RenderWindow* Game::getWindow() const {
    return _context->_window.get();
}


float Game::getFPS() const {
    return _framesPerSecond;
}

void Game::setFPS(float fps) {
    _framesPerSecond = fps;
    _context->_window->setFramerateLimit(_framesPerSecond);
    _timePerFrame = sf::seconds(1.0f / _framesPerSecond);
}

bool Game::getVSync() const {
    return _VSyncFlag;
}

void Game::setVSync(bool flag) {
    _VSyncFlag = flag;
    _context->_window->setVerticalSyncEnabled(_VSyncFlag);
}

sf::Vector2u Game::getResolution() const {
    return _context->_window->getSize();
}

void Game::setResolution(unsigned width, unsigned height) {
    _windowWidth = width;
    _windowHeight = height;
    _context->_window.reset(new sf::RenderWindow(sf::VideoMode(_windowWidth, _windowHeight), _titleBarText));
    /*
    delete _window;
    _windowWidth = width;
    _windowHeight = height;
    _window = new sf::RenderWindow(sf::VideoMode(_windowWidth, _windowHeight), _titleBarText);
    */
}

std::string Game::getTitleBarText() const {
    return _titleBarText;
}

void Game::setTitleBarText(const std::string& text) {
    _titleBarText = text;
    _context->_window->setTitle(_titleBarText);
}

