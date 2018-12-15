// -*- mode: c++; tab-width: 4 -*-
// File: driver.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 6

#ifndef DRIVER_HPP_
#define DRIVER_HPP_

#include "blockchain.hpp"

class Driver {
private:
	Blockchain bc[10]; // array of 10 blockchains

public:
	Driver(); // override the default constructor
	void begin();
};

#endif /* DRIVER_HPP_ */
