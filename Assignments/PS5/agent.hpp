// -*- mode: c++; tab-width: 4 -*-
// File: agent.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 5

#pragma once

#include "tools.hpp"

// Pure abstract class where all functions are virtual and all are
// abstract except for virtual destrucotr.
class Agent {

public:
	virtual ~Agent() {}

	virtual void update(int m) = 0;
	virtual int choice() const = 0;
};
