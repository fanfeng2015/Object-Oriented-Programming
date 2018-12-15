// -*- mode: c++; tab-width: 4 -*-
// File: fickle.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 7

#ifndef FICKLE_HPP
#define FICKLE_HPP

#include "agentbase.hpp"

class Fickle : public AgentBase {
public:
	Fickle(Blockchain bc) { cur = bc; }

	// Update the current blockchain.
	virtual void update(Blockchain bc) { cur = bc; }
};

#endif
 