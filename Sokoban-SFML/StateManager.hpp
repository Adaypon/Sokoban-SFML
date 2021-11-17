#pragma once

#include <stack>
#include <memory>
#include "State.hpp"

typedef std::unique_ptr<State> StateRef;	

class StateManager {
private:
	// should be modified at the start of next update() cycle
	std::stack<std::unique_ptr<State>> _stateStack;

	// storing the new state being added to stack
	// because it's not necessary to push a new state
	// while other state is executing it's update() method
	std::unique_ptr<State> _newState;

	bool _isAdding;
	bool _isReplacing;
	bool _isRemoving;
public:
	StateManager();
	~StateManager();

	// Add new state to stack
	void addState(StateRef newState, bool replaceFlag = false); // most of the time just want to push state on stack
	
	// Remove current state from stack
	void popState(); 

	// Process state change
	void changeState(); // runs at the start of each loop in Game.cpp

	// Get current state
	StateRef& getCurrentState();

};

