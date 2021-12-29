#include "StateManager.hpp"

StateManager::StateManager() :
	_isAdding(false),
	_isReplacing(false),
	_isRemoving(false)
{

}

StateManager::~StateManager() {

}

void StateManager::addState(StateRef newState, bool replaceFlag) {
	_isAdding = true;
	_newState = std::move(newState);
	_isReplacing = replaceFlag;
	//std::cout << "addState(): moved state to _newState" << std::endl;
}

void StateManager::popState() {
	_isRemoving = true;
}

void StateManager::changeState() {
	if (_isRemoving && !_stateStack.empty()) {
		_stateStack.pop();
		
		if (!_stateStack.empty()) {
			_stateStack.top()->resume();
		}

		_isRemoving = false;
	}

	if (_isAdding) {
		if (_isReplacing && !_stateStack.empty()) {
			_stateStack.pop();
			_isReplacing = false;
		}

		if (!_stateStack.empty()) {
			_stateStack.top()->pause();
		}

		//std::cout << "addState(): pushing _newState" << std::endl;
		_stateStack.push(std::move(_newState));
		//std::cout << "addState(): calling top->init()" << std::endl;
		_stateStack.top()->init();
		//std::cout << "addState(): calling top->resume()" << std::endl;
		_stateStack.top()->resume();
		_isAdding = false;
	}
}

StateRef& StateManager::getCurrentState() {
	return _stateStack.top();
}