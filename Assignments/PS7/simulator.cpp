// -*- mode: c++; tab-width: 4 -*-
// File: simulator.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 7

#include "simulator.hpp"

// Constructor
Simulator::Simulator( Population& p ) {
    population = &p;
}

// Choose a random real number in [0, 1).
double Simulator::doubleRandom() {
    return random() / (RAND_MAX + 1.0); // result is double in [0, 1)
}

// Select a random agent from among n agents.
int Simulator::uniformRandom( int n ) {
	long int usefulMax = RAND_MAX - (RAND_MAX - n + 1) % n;
	long int r;
	do { r = random(); }
	while ( r > usefulMax );
	return r % n;
}

// Run the simulation for up to the input max rounds.
void Simulator::run( int maxRounds, double probExtend ) {
    for (int i = 0; i < maxRounds; i++) {
        if (doubleRandom() < probExtend) { // choose an agent at random to extend
            int rand = uniformRandom( population -> size() );
            population -> extend( rand );
        }
        else { // send a message
            int j = uniformRandom( population -> size() );     // sender
            int k = uniformRandom( population -> size() - 1 ); // receiver
            k = (k >= j) ? (k + 1) : k;
            population -> sendMessage(j, k);
        }
    }
    // print out a list of agents with each agent's current choice
    cout << "Current blockchain choices after " << maxRounds <<  " rounds: " << endl;
    population -> print();
}
