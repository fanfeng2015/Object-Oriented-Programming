// -*- mode: c++; tab-width: 4 -*-
// File: block.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 8

#include "block.hpp"

// Print a single block
void Block::print() const {
	cout << "[" << blkLevel() << ", " << blkSerial() << "]";
}

// Print entire block chain
void Block::printChain() const { // recursive
	Block* prev = sptr.tar();
	if (prev == nullptr) {       // base case
		print();
		return ;
	}
	prev -> printChain();        // recursive rule
	cout << ", ";
	print();
}
