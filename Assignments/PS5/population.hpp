// -*- mode: c++; tab-width: 4 -*-
// File: population.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 5

#include "agent.hpp"

// Pure abstract class where all functions are virtual and all are
// abstract except for virtual destrucotr.
class Population {
private:
	int zeros, ones;
	Agent** agents; // fully dynamic aggregation
	
	double doubleRandom();

public:
	Population ( int numAgents, double probFickle, double prodOne );
	~Population();

	int size() const;
	void sendMessage(int sender, int receiver);
	bool consensusReached();
	int consensusValue();
};

// TODO: copy constructor
