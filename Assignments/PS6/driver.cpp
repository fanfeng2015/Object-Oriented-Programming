// -*- mode: c++; tab-width: 4 -*-
// File: driver.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 6

#include <cctype>
#include "block.hpp"
#include "driver.hpp"

// Override the default constructor
Driver::Driver() {
	// heap allocated, default constructor of Block & SPtr (count = 0)
	Block* genesis = new Block(); 
	// stack allocated, custom constructor of Blockchain & SPtr (count = 1)
	Blockchain temp( genesis ); // destructed upon return
	for (int i = 0; i < 10; i++) {
		// copy constructor of Blockchain & SPtr (count++)
		bc[i] = temp; 
	}
	// destructor of Blockchain & SPtr (count--)
}

// Prompt user for command and take corresponding action.
void Driver::begin() {
	char cmd, i, j, k; // store single letter command
	for ( ; ; ) {
		cout << "Please enter a command: ";
		cin >> cmd;
		cmd = toupper( cmd );
		switch( cmd ) {
			case 'A':
				cin >> j;
				cin >> k;
				bc[j - '0'] = bc[k - '0'];
				continue;
			case 'E':
				cin >> i;
				bc[i - '0'] = bc[i - '0'].extend(); // copy assignment of Blockchain, SPtr (count--)
				continue;
			case 'P':
				for (int x = 0; x < 10; x++) {
					bc[x].print();
					cout << endl;
				}
				continue;
			case 'Q':
				cout << "Exiting..." << endl;
				return;
			default:
				cin.clear();
				cout << "Invalid command. Please try again..." << endl;
		}
	}
}
