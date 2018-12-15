// -*- mode: c++; tab-width: 4 -*-
// File: block.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 6

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "SPtr.hpp"

class Block {
private:
	const SPtr sptr;
	const int level = 0;                // level in the blockchain tree (genesis block is at level 0)
	const int serial = Serial::newID(); // unique identifier

public:
	// Constructor
    Block() = default;
	Block(SPtr sp, int lv) : sptr(sp), level(lv) {} // ctor to initialize, = to assign
	~Block() = default;

    // Copy constructor
    Block(const Block& block) = delete;
    // Copy assignment
    Block& operator =(const Block& block) = delete;

    int blkLevel() const { return level; }
    int blkSerial() const { return serial; }

    void print() const;
    void printChain() const; 
};

#endif /* BLOCK_HPP_ */
