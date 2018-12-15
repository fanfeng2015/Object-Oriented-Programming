// -*- mode: c++; tab-width: 4 -*-
// File: simulator.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 4

#include "agent.hpp"

class Simulator {
private:
	int zeros, ones;
	Agent* agents; // aggregation
	
	int uniformRandom( int n );

public:
	Simulator ( int numAgents, int numOne, int seed );
	~Simulator();

	int run( int& rounds );
};

// TODO: copy constructor
