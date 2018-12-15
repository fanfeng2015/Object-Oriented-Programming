// -*- mode: c++; tab-width: 4 -*-
// File: simulator.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 8

#include "population.hpp"

class Simulator {
private:
	Population* population;

	double doubleRandom();
	int uniformRandom( int n );

public:
	Simulator( Population& p );
	~Simulator() = default;

	void run( int maxRounds, double probExtend );
};

// Question: destructor? copy constructor?
