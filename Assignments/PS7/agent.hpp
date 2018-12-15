// -*- mode: c++; tab-width: 4 -*-
// File: agent.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 7

#pragma once

#include "blockchain.hpp"

// Pure abstract class where all functions are virtual and all are
// abstract except for virtual destrucotr.
class Agent {

public:
	virtual ~Agent() {}

	// Update the current blockchain.
	virtual void update(Blockchain bc) = 0;
	// Extend the current blockchain and make the extended blockchain its new choice.
	virtual void extend() = 0;

	// Return the current blockchain.
	virtual Blockchain choice() const = 0;
	// Print the current blockchain.
	virtual void print() const = 0;
};
