// -*- mode: c++; tab-width: 4 -*-
// File: blockchain.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 7

#ifndef BLOCKCHAIN_HPP_
#define BLOCKCHAIN_HPP_

#include "SPtr.hpp"
#include "block.hpp"

class Blockchain {
private:
	SPtr sptr; // to the most recent block in the chain

public:
	Blockchain() = default;
	Blockchain(Block* block) : sptr(SPtr(block)) {}
	~Blockchain() = default;

    Blockchain extend();
    
    Block* tar() const;
	void print() const;
};

inline bool operator== (const Blockchain& lhs, const Blockchain& rhs) {
	return lhs.tar() -> blkSerial() == rhs.tar() -> blkSerial();
}

inline bool operator!= (const Blockchain& lhs, const Blockchain& rhs) {
    return !(lhs == rhs);
}

inline ostream& operator<< (ostream & out, Blockchain& bc) {
	bc.print();
	return out;
}

#endif /* BLOCKCHAIN_HPP_ */
