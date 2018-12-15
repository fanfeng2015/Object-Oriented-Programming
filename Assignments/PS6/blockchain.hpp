// -*- mode: c++; tab-width: 4 -*-
// File: blockchain.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 6

#ifndef BLOCKCHAIN_HPP_
#define BLOCKCHAIN_HPP_

#include "block.hpp"
#include "SPtr.hpp"

class Blockchain {
private:
	SPtr sptr; // to the most recent block in the chain

public:
	Blockchain() = default;
	Blockchain(Block* block) : sptr(SPtr(block)) {}
	~Blockchain() = default;

    Blockchain extend();
	void print() const;
};

inline ostream& operator<< (ostream & out, Blockchain& bc) {
	bc.print();
	return out;
}

#endif /* BLOCKCHAIN_HPP_ */
