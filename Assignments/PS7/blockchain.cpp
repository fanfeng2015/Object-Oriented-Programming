// -*- mode: c++; tab-width: 4 -*-
// File: blockchain.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 7

#include "blockchain.hpp"

// Extend the current blockchain.
Blockchain Blockchain::extend() {
	Block* prev = sptr.tar(); // prev block
	// construct block on the current blockchain
	// heap allocated, custom constructor of Block, copy constructor of SPtr (count++)
	Block* block = new Block( sptr, prev -> blkLevel() + 1 );
	// stack allocated, custom constructor of Blockchain & SPtr (count = 1)
	Blockchain nextbc( block ); // destructed upon return
	return nextbc;
}

// Return the most recent block of the current blockchain.
Block* Blockchain::tar() const {
	return sptr.tar();
}

// Print the current blockchain.
void Blockchain::print() const {
	Block* prev = sptr.tar(); // prev block (most recent in the chain)
	prev -> printChain();
}
