// -*- mode: c++; tab-width: 4 -*-
// File: simulator.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 5

#include "population.hpp"

class Simulator {
private:
	int rounds;
	Population* population;
	
	int uniformRandom( int n );

public:
	Simulator( Population& population );
	~Simulator() = default;

	int numRounds();
	int consensusValue();
	void run();
};

// Question: destructor? copy constructor?
