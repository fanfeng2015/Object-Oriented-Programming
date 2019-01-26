// -*- mode: c++; tab-width: 4 -*-
// File: flipflop.hpp---------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 3

#ifndef FLIPFLOP_HPP_
#define FLIPFLOP_HPP_

#include "tools.hpp"

class FlipFlop {
private:
	enum State { LEFT, RIGHT };
	State state = LEFT;

public:
	FlipFlop() = default;

	// Get the current state of the flip-flop.
	char getState() { return (state == LEFT) ? 'L' : 'R'; }
	
	// Set the current state of the flip-slop.
	void setState( char ch ) { state = (ch == 'L') ? LEFT : RIGHT; }
	
	// Flip the current state of the flip-flop.
	State flip() {
		state = (state == LEFT) ? RIGHT : LEFT;
		return state; 
	}

	// Print 'L' or 'R' depending on the currenrt state of the flip-flop.
	void print( ostream& out ) const {
		char ch = (state == LEFT) ? 'L' : 'R';
		cout << ch << " ";
	}
};

#endif /* FLIPFLOP_HPP_ */
