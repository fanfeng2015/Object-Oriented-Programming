// -*- mode: c++; tab-width: 4 -*-
// File: main.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 4

#include <string>
#include "simulator.hpp"

using namespace std;

void run( int numAgents, int numOne, int seed );

int main( int argc, char** argv ) {
    if (argc < 3 || argc > 4) {
        fatal("Usage: $ consensus numAgents numOne [seed]");
    }
    int numAgents = stoi( argv[1] );
    int numOne = stoi( argv[2] );
    int seed = time(0);
    if (argc == 4) {
    	seed = stoi( argv[3] );
    }
    run( numAgents, numOne, seed );
}

// Instantiate Simulator and call run().
void run( int numAgents, int numOne, int seed ) {
	Simulator simulator( numAgents, numOne, seed ); // constructor
	int rounds = 0;
	int consensus = simulator.run( rounds ); // run simulator
	cout << numAgents << " " << numOne << " " << seed << " "
		 << rounds << " " << consensus << endl;
}
