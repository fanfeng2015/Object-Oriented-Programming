// -*- mode: c++; tab-width: 4 -*-
// File: simulator.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 4

#include "simulator.hpp"

// Constructor
Simulator::Simulator( int numAgents, int numOne, int seed ) {
	srandom( seed );
	zeros = numAgents - numOne;
	ones = numOne;
	agents = new Agent[numAgents]; // aggregation always uses the default constructor
	// the first numOne have initial choince 1, the remainder have initial choice 0
	for (int i = 0; i < numAgents; i++) {
		int m = (i < numOne) ? 1 : 0;
		agents[i].update(m); // or agents[i] = Agent(m);
	}
}

// Destructor
Simulator::~Simulator() {
	delete[] agents;
}

// Select a random agent from among n agents.
int Simulator::uniformRandom( int n ) {
	long int usefulMax = RAND_MAX - (RAND_MAX - n + 1) % n;
	long int r;
	do { r = random(); }
	while ( r > usefulMax );
	return r % n;
}

// Run the simulation for as many rounds as needed to reach consensus.
int Simulator::run( int& rounds ) {
	const int threshold = 3;
    const time_t start = time(nullptr);
    while ( difftime( time(nullptr), start ) < threshold ) {
    	if (zeros == 0 || ones == 0) {
    		return (zeros == 0) ? 1 : 0;
    	}
    	rounds++;
    	int j = uniformRandom( zeros + ones ); // sender
    	int k = uniformRandom( zeros + ones - 1 ); // receiver
    	k = (k >= j) ? (k + 1) : k;
    	if (agents[k].choice() != agents[j].choice()) {
    		if (agents[k].choice() == 0) {
    			zeros--;
    			ones++;
    		}
    		else {
    			zeros++;
    			ones--;
    		}
    		agents[k].update(agents[j].choice());
    	}
    }
    return -1;
}
