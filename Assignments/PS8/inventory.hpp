// -*- mode: c++; tab-width: 4 -*-
// File: inventory.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 8

using namespace std;

class Inventory {
private:
	map<Blockchain, int> bc2freq; // blockchain to frequency

public:
	Inventory() = default;
	~Inventory() = default;

	void add(Blockchain bc) {
		map<Blockchain, int>::iterator itr = bc2freq.find(bc);
		if (itr != bc2freq.end()) { // not exist
			bc2freq[bc]++;
		}
		else { // exist, increment frequency
			bc2freq.insert( pair<Blockchain, int>(bc, 1) );
		}
	}

	void sub(Blockchain bc) {
		map<Blockchain, int>::iterator itr = bc2freq.find(bc); // must exist
		if (itr -> second > 1) {
			bc2freq[bc]--;
		}
		else {
			bc2freq.erase(bc);
		}
	}

	void print() {
    	map<Blockchain, int>::iterator itr; 
	    for (itr = bc2freq.begin(); itr != bc2freq.end(); itr++) { 
	        cout << "  " << itr->second << " copies of \t";
	        (itr->first).print();
	        cout << endl; 
	    }
	    cout << endl;
	}
};
