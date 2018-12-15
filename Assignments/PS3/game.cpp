// -*- mode: c++; tab-width: 4 -*-
// File: game.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 3

#include <cctype>
#include "game.hpp"

// Prompt user for command and take corresponding action.
void Game::play() {
	tad.reset('R');
	char cmd;
	for ( ; ; ) {
		cout << "Please enter a command: ";
		cin >> cmd;
		cmd = toupper(cmd);
		switch (cmd) {
			case 'Q': 
				cout << "Exiting..." << endl; 
				break;
			case 'H': 
				cout << "Usage: " << endl; 
				cout << "  A/B/C: Drop a ball in hole A/B/C." << endl;
				cout << "  L/R: Reset all gates to L/R." << endl;
				cout << "  P: Print the current state of the board." << endl;
				continue;
			case 'P':
				tad.print(cout);
				continue;
			case 'L':
				tad.reset(cmd);
				continue;
			case 'R':
				tad.reset(cmd);
				continue;
			case 'A':
			tad.play(cmd);
				continue;
			case 'B':
			tad.play(cmd);
				continue;
			case 'C':
			tad.play(cmd);
				continue;
			default:
				cout << "Invalid command. Please try again..." << endl;
				continue;
		}
		break;
	}
}
