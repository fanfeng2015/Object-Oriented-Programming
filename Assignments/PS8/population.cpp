// -*- mode: c++; tab-width: 4 -*-
// File: population.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 8

#include "nakamoto.hpp"
#include "fickle.hpp"
#include "crowd.hpp"
#include "blockchain.hpp"
#include "population.hpp"

// Constructor
Population::Population( int numAgents, double probNak, double probFickle ) {
    count = numAgents;
    agents = new Agent*[numAgents]; // fully dynamic aggregation
    int nakamoto = 0, fickle = 0, crowd = 0;

    Block* genesis = new Block();
    Blockchain temp(genesis);
    for (int i = 0; i < numAgents; i++) {
        inventory.add(temp); // add to inventory
        // decide type of agent (nakamoto / fickle / crowd)
        double rand = doubleRandom();
        if (rand < probNak) {
            agents[i] = new Nakamoto(temp);
            nakamoto++;
        }
        else if (rand < probNak + probFickle){
            agents[i] = new Fickle(temp);
            fickle++;
        }
        else {
            agents[i] = new Crowd(temp);
            crowd++;
        }
    }
    // print population statistics
    cout << "Population statistics: " << endl;
    cout << "       numNak: " << nakamoto << endl;
    cout << "    numFickle: " << fickle << endl;
    cout << "     numCrowd: " << crowd << endl;
    cout << endl;

    inventory.print(); // print out inventory
}

// Destructor
Population::~Population() {
    for (int i = 0; i < count; i++) {
        delete agents[i];
    }
    delete[] agents;
}

// Choose a random real number in [0, 1).
double Population::doubleRandom() {
    return random() / (RAND_MAX + 1.0); // result is double in [0, 1)
}

// Extend the agent indexed at receiver.
void Population::extend(int receiver) {
    Blockchain prev = agents[receiver] -> choice();
    agents[receiver] -> extend();
    if (agents[receiver] -> choice() != prev) { // add to or subtract from inventory
        inventory.add( agents[receiver] -> choice() );
        inventory.sub( prev );
        inventory.print();
    }
}

// Simulate a single communication step from sender to receiver.
void Population::sendMessage(int sender, int receiver) {
    Blockchain prev = agents[receiver] -> choice();
    agents[receiver] -> update(agents[sender] -> choice());
    if (agents[receiver] -> choice() != prev) { // add to or subtract from inventory
        inventory.add( agents[receiver] -> choice() );
        inventory.sub( prev );
        inventory.print();
    }
}

// Return the number of agents.
int Population::size() const {
    return count;
}

// Print out a list of agents with each agent's current choice.
void Population::print() const {
    for (int i = 0; i < count; i++) {
        cout << "Agent " << i << " choice: ";
        agents[i] -> print();
    }
}
