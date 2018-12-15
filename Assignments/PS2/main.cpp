// -*- mode: c++; tab-width: 4 -*-
// File: main.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 2

#include "tools.hpp"

void run( char* filename );

int main( int argc, char** argv ) {
    banner();
    if (argc != 2) {
        fatal("Usage: 2 arguments expected, %d argument(s) " 
              "provided... Exiting.", argc);
    } 
    run( argv[1] );
    bye();
}

// Prints integer values in the file named with filename. Skips non-integer 
// values by printing their dec, hex, and char representations instead.
void run( char* filename ) {
    ifstream in( filename );
    if (!in) {
        fatal("Error opening file %s... Exiting.", filename);
    }

    int x;
    char ch;
    do {
        in >> x;
        if (!in.fail()) {
            cout << dec << x << endl;
        }
        else if (!in.eof()) {
            // clear the fail bit so that the rest of the file can be read
            in.clear();
            in.get( ch );
            cout << "Skipping char: " << setfill(' ') << setw(3) << dec 
                 << (int) ch << " 0x" << setfill('0') << setw(2) << hex
                 << (int) ch;
            if (isprint( ch )) {
                cout << " '" << ch << "'";
            }
            cout << endl;
        }
    } while (in.good());

    cout << "Loop exit";
    in.close();
}

