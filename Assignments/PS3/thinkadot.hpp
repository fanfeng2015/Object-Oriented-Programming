// -*- mode: c++; tab-width: 4 -*-
// File: thinkadot.hpp---------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 3

#ifndef THINKADOT_HPP_
#define THINKADOT_HPP_

#include "flipflop.hpp"

class ThinkADot {
public:
	enum InHole { A, B, C };	// names of the input holes
	enum OutHole { P, Q };		// names of the output holes

private:
	// names of the gates and exit directions
	enum Place { T0, T1, T2, M0, M1, B0, B1, B2, LEXIT, REXIT };
	// place where ball goes when gate points left
	const Place nextLeft[8] = {
		B0, M0, M1,				// top row
		B0, B1, 				// middle row
		LEXIT, LEXIT, REXIT		// bottom row
	};
	FlipFlop gate[8];			// Think-A-Dot gates in row major order
	bool isExit(Place pl) { return pl == LEFT || pl == RIGHT; }

public:
	ThinkADot( FlipFlop::Direction const dir );
	void reset( FlipFlp::Direction dir );
	OutHole play( InHole start );
	ostream& print( ostream& out ) const;
};

// ----------------------------------------------------------------------------------
inline
ostream& operator<<( ostream& out, const ThinkADot& m) {
	return m.print(out);
}

inline 
ostream& operator<<( ostream& out, const ThinkADot::OutHole oh ) {
	switch( oh ) {
		case ThinkADot::OutHole::P: out << "  Ball exits at P" << endl; break;
		case ThinkADot::OutHole::Q: out << "  Ball exits at Q" << endl; break; 
	}
	return out;
}

#endif /* THINKADOT_HPP_ */
