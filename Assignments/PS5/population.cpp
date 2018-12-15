// -*- mode: c++; tab-width: 4 -*-
// File: population.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 5

#include "fickle.hpp"
#include "crowd.hpp"
#include "population.hpp"

// Constructor
Population::Population( int numAgents, double probFickle, double probOne ) {
    zeros = 0;
    ones = 0;
    agents = new Agent*[numAgents]; // fully dynamic aggregation
    int val = 0, fickle = 0, crowd = 0;
    for (int i = 0; i < numAgents; i++) {
        // decide value of agent (0 / 1)
        if (doubleRandom() < probOne) {
            val = 1;
            ones++;
        }
        else {
            val = 0;
            zeros++;
        }
        // decide type of agent (fickle / crowd)
        if (doubleRandom() < probFickle) {
            agents[i] = new Fickle(val);
            fickle++;
        }
        else {
            agents[i] = new Crowd(val);
            crowd++;
        }
    }
    cout << "Population statistics: " << endl;
    cout << "    numFickle: " << fickle << endl;
    cout << "     numCrowd: " << crowd << endl;
    cout << "      numOnes: " << ones << endl;
}

// Destructor
Population::~Population() {
    for (int i = 0; i < zeros + ones; i++) {
        delete agents[i];
    }
    delete[] agents;
}

// Choose a random real number in [0, 1).
double Population::doubleRandom() {
    return random() / (RAND_MAX + 1.0); // result is double in [0, 1)
}

// Return the number of agents.
int Population::size() const {
    return zeros + ones;
}

// Simulate a single communication step from sender to receiver.
void Population::sendMessage(int sender, int receiver) {
    int prev = agents[receiver] -> choice();
    agents[receiver] -> update(agents[sender] -> choice());
    if (agents[receiver] -> choice() != prev) { // receiver's value changed
        if (prev == 0) {
            zeros--;
            ones++;
        }
        else {
            zeros++;
            ones--;
        }
    }
}

// Return true iff a consensus has been reached.
bool Population::consensusReached() {
    return zeros == 0 || ones == 0;
}

// Return the consenses value if consensus has been reached, -1 otherwise.
int Population::consensusValue() {
    if (zeros == 0 || ones == 0) {
        return (zeros == 0) ? 1 : 0;
    }
    return -1;
}
