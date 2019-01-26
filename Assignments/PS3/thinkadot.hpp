// -*- mode: c++; tab-width: 4 -*-
// File: thinkadot.hpp---------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 3

#ifndef THINKADOT_HPP_
#define THINKADOT_HPP_

#include "flipflop.hpp"

class ThinkADot {
private:
	FlipFlop ffs[8];

public:
	ThinkADot() = default;
	void play(char cmd);
	void reset(char cmd);
	void print( ostream& out ) const;
};

#endif /* THINKADOT_HPP_ */
