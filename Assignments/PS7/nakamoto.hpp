// -*- mode: c++; tab-width: 4 -*-
// File: nakamoto.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 7

#ifndef NAKAMOTO_HPP
#define NAKAMOTO_HPP

#include "agentbase.hpp"

class Nakamoto : public AgentBase {
public:
	Nakamoto(Blockchain bc) { cur = bc; }

	// Update the current blockchain.
	virtual void update(Blockchain bc) {
		if (cur.tar() -> blkLevel() < bc.tar() -> blkLevel()) {
			cur = bc;
		}
	}
};

#endif
