// -*- mode: c++; tab-width: 4 -*-
// File: thinkadot.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 3

#include "thinkadot.hpp"

// Construct machine with all gates intialized in direction dir.
ThinkADot::
ThinkADot( FlipFlop::Direction const dir ) {
	reset( dir );
}

// Reset all gate to direction dir.
void ThinkADot::
reset( FlipFlp::Direction dir ) {
	for (int i = 0; i < 8; i++) {
		gates[i] = FlipFlop( dir );
	}
}

// Simulate passage of ball through the machine. Return exit point.
ThinkADot::OutHole ThinkADot::
play( InHole h ) {
	Place pl;
	switch( h ) {
		case A:
			pl = T0;
			break;
		case B:
			pl = T1;
			break;
		case C:
			pl = T2;
			break;
	}

	// int table[6][2] = {
	// 	{ 0, 0 },
	// 	{ 6, 4 },
	// 	{ 4, 5 },
	// 	{ 5, 8 }, 
	// 	{ 6, 7 },
	// 	{ 7, 8 }
	// };
	// int index = (cmd - 'A') + 1;
	// while (index < 6) {
	// 	int col = (ffs[index - 1].getState() == 'L') ? 0 : 1;
	// 	ffs[index - 1].flip();
	// 	index = table[index][col];
	// }
	// char exit = 'P';
	// if ((index == 7 && ffs[6].getState() == 'R') || (index == 8)) {
	// 	exit = 'Q';
	// }
	// ffs[index - 1].flip();
	// cout << "Exit from hole " << exit << "..." << endl;
}


// Print the current state of the board.
void ThinkADot::print( ostream& out ) const {
	ffs[0].print(out);
	ffs[1].print(out);
	ffs[2].print(out);
	cout << endl;
	cout << " ";
	ffs[3].print(out);
	ffs[4].print(out);
	cout << endl;
	ffs[5].print(out);
	ffs[6].print(out);
	ffs[7].print(out);
	cout << endl;
}


