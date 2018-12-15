// -*- mode: c++; tab-width: 4 -*-
// File: crowd.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 8

#ifndef CROWD_HPP
#define CROWD_HPP

#include "agentbase.hpp"

class Crowd : public AgentBase {
private:
	// current value of agent is inherited from AgentBase
	Blockchain state; // current state of agent

public:
	Crowd(Blockchain bc) { 
		cur = bc; 
		state = bc; 
	}

	// Update the current blockchain.
	virtual void update(Blockchain bc) {
		if (state != bc) {
			state = bc;
		}
		else {
			cur = bc;
		}
	}
};

#endif
