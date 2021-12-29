#pragma once

#include <stack>
#include <memory>
#include "State.hpp"

class State;

typedef std::unique_ptr<State> StateRef;	

// Class of state management
class StateManager {
private:
	// Stack for storing the states. Should be modified at the start of next update() cycle
	std::stack<StateRef> _stateStack;

	// Storing the new state being added to stack,
	// because it's not necessary to push a new state
	// while other state is executing it's update() method
	StateRef _newState;

	bool _isAdding; 
	bool _isReplacing;
	bool _isRemoving;
public:
	StateManager();
	~StateManager();

	/**
	* Add new state to stack
	* @param newState Unique pointer to state being added
	* @param replaceFlag Boolean for replacing the current state with the new one
	*/
	void addState(StateRef newState, bool replaceFlag = false); // most of the time just want to push state on stack
	
	// Remove current state from stack
	void popState(); 

	// Process state change
	void changeState(); // runs at the start of each loop in Game.cpp

	/**
	* Get current state
	* @return Reference to unique pointer of State
	*/
	StateRef& getCurrentState();
};