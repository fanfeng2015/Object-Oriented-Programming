// -*- mode: c++; tab-width: 4 -*-
// File: population.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 7

#include "agent.hpp"

// Pure abstract class where all functions are virtual and all are
// abstract except for virtual destrucotr.
class Population {
private:
	int count;
	Agent** agents; // fully dynamic aggregation
	
	double doubleRandom();

public:
	Population ( int numAgents, double probNak, double probFickle );
	~Population();

	void extend(int receiver);
	void sendMessage(int sender, int receiver);

	int size() const;
	void print() const;
};

// TODO: copy constructor
