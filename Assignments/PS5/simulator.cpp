// -*- mode: c++; tab-width: 4 -*-
// File: simulator.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 5

#include "simulator.hpp"

// Constructor
Simulator::Simulator( Population& p ) {
    rounds = 0;
    population = &p;
}

// Select a random agent from among n agents.
int Simulator::uniformRandom( int n ) {
	long int usefulMax = RAND_MAX - (RAND_MAX - n + 1) % n;
	long int r;
	do { r = random(); }
	while ( r > usefulMax );
	return r % n;
}

// Return the number of rounds of simulation.
int Simulator::numRounds() {
    return rounds;
}

// Return the final consensus value.
int Simulator::consensusValue() {
    return population -> consensusValue();
}

// Run the simulation for as many rounds as needed to reach consensus.
void Simulator::run() {
    const int threshold = 10; // seconds
    const time_t start = time(nullptr);
    while ( difftime( time(nullptr), start ) < threshold && !population -> consensusReached() ) {
        rounds++;
        int j = uniformRandom( population -> size() ); // sender
        int k = uniformRandom( population -> size() - 1 ); // receiver
        k = (k >= j) ? (k + 1) : k;
        population -> sendMessage(j, k);
    }
}
