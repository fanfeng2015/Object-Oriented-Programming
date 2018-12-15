// -*- mode: c++; tab-width: 4 -*-
// File: agentbase.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 8

#pragma once

#include "agent.hpp"

// Class AgentBase publicly derived from Agent and from which Fickle, Crowd and 
// Nakamoto publicly derive.
class AgentBase : public Agent {
protected:
	Blockchain cur; // current blockchain

public:
	virtual ~AgentBase() {}

	// Update the current blockchain.
	virtual void update(Blockchain bc) = 0;
	// Extend the current blockchain and make the extended blockchain its new choice.
	virtual void extend() { cur = cur.extend(); }

	// Return the current blockchain.
	virtual Blockchain choice() const { return cur; }
	// Print the current blockchain.
	virtual void print() const { 
		cur.print(); 
		cout << endl; 
	}
};
