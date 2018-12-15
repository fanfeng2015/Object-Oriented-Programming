// -*- mode: c++; tab-width: 4 -*-
// File: main.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 8

#include <string>
#include "simulator.hpp"

using namespace std;

void run( int numAgents, int maxRounds, double probNak, double probFickle, double probExtend );

int main( int argc, char** argv ) {
    banner();
    if (argc < 6 || argc > 7) {
        fatal("Usage: $ blockchain numAgents maxRounds " 
              "probNak probFickle probExtend [seed]");
    }
    int numAgents = stoi( argv[1] );
    int maxRounds = stoi( argv[2] );
    double probNak = stod( argv[3] ); 
    double probFickle = stod( argv[4] ); // probCrowd = 1.0 − probNak − probFickle
    double probExtend = stod( argv[5] );

    int seed = time(0);
    if (argc == 7) {
    	seed = stoi( argv[6] );
    }
    srandom(seed);

    cout << "Welcome to Consensus Simulator!" << endl;
    cout << "Using seed: " << seed << endl;
    cout << "    numAgents: " << numAgents << endl;
    cout << "    maxRounds: " << maxRounds << endl;
    cout << "      probNak: " << probNak << endl;
    cout << "   probFickle: " << probFickle << endl;
    cout << "   probExtend: " << probExtend << endl;
    cout << endl;

    run( numAgents, maxRounds, probNak, probFickle, probExtend );
    bye();
}

// Instantiate Simulator and call run().
void run( int numAgents, int maxRounds, double probNak, double probFickle, double probExtend ) {
    Population population( numAgents, probNak, probFickle );  // constructor
    Simulator simulator( population ); // constructor
    simulator.run( maxRounds, probExtend );
}
