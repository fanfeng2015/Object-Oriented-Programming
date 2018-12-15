// -*- mode: c++; tab-width: 4 -*-
// File: blockchain.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 6

#include "blockchain.hpp"

Blockchain Blockchain::extend() {
	Block* prev = sptr.tar(); // prev block
	// construct block on the current blockchain
	// heap allocated, custom constructor of Block, copy constructor of SPtr (count++)
	Block* block = new Block( sptr, prev -> blkLevel() + 1 );
	// stack allocated, custom constructor of Blockchain & SPtr (count = 1)
	Blockchain nextbc( block ); // destructed upon return
	return nextbc;
}

void Blockchain::print() const {
	Block* prev = sptr.tar(); // prev block (most recent in the chain)
	prev -> printChain();
}
