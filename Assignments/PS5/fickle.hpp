// -*- mode: c++; tab-width: 4 -*-
// File: fickle.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 5

#ifndef FICKLE_HPP
#define FICKLE_HPP

#include "agent.hpp"
#include "tools.hpp"

class Fickle : public Agent {
private:
	int cur;

public:
	Fickle(int ch);
	virtual ~Fickle() = default;

	virtual void update(int m);
	virtual int choice() const;
};

#endif
