// -*- mode: c++; tab-width: 4 -*-
// File: blockchain.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 8

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

inline bool operator< (const Blockchain& lhs, const Blockchain& rhs) {
	// Compare level first, then serial number.
	if (lhs.tar() -> blkLevel() == rhs.tar() -> blkLevel()) {
		return lhs.tar() -> blkSerial() < rhs.tar() -> blkSerial();
	}
	return lhs.tar() -> blkLevel() > rhs.tar() -> blkLevel();
}

inline bool operator== (const Blockchain& lhs, const Blockchain& rhs) {
	// If serial numbers are equal, then levels must equal.
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
