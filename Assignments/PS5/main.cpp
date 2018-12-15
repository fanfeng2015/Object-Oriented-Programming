// -*- mode: c++; tab-width: 4 -*-
// File: main.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 5

#include <string>
#include "simulator.hpp"

using namespace std;

void run( int numAgents, double probFickle, double prodOne );

int main( int argc, char** argv ) {
    banner();
    if (argc < 4 || argc > 5) {
        fatal("Usage: $ consensus2 numAgents probFickle probOne [seed]");
    }
    int numAgents = stoi( argv[1] );
    double probFickle = stod( argv[2] );
    double probOne = stod( argv[3] );

    int seed = time(0);
    if (argc == 5) {
    	seed = stoi( argv[4] );
    }
    srandom(seed);

    cout << "Welcome to Consensus Simulator!" << endl;
    cout << "Using seed: " << seed << endl;
    cout << "    numAgents: " << numAgents << endl;
    cout << "   probFickle: " << probFickle << endl;
    cout << "      probOne: " << probOne << endl;

    run( numAgents, probFickle, probOne );
    bye();
}

// Instantiate Simulator and call run().
void run( int numAgents, double probFickle, double prodOne ) {
    Population population( numAgents, probFickle, prodOne ); // constructor
    Simulator simulator( population ); // constructor
    simulator.run();

    cout << "Results of simulation: " << endl;
    cout << "       Rounds: " << simulator.numRounds() << endl;
    cout << "    Consensus: " << simulator.consensusValue() << endl;
}
