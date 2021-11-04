#include "State.hpp"

State::State(Game* game) :
	_game(game)
{

}

State::~State() {

}

Game* State::getGame() const {
	return _game;
}