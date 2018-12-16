//===========================================================================
// Class for a linked-list row and its cells
// A. Fischer, October 1, 2000                                  file: row.hpp
// Modified M. & A. Fischer, September 17, 2009
//===========================================================================
#pragma once
#include <iostream>
#include "item.hpp"
using namespace std;
//---------------------------------------------------------------------------
// Dependent class. Holds an Item and a link to another Cell.
class Cell {
    friend class Row; // Row can access Item* data and Cell* next in Cell.
private:
    Item* data;           // Pointer to one data Item    (Aggregation)
    Cell* next;           // Pointer to next cell in row (Association)

    Cell(char* d, int s, Cell* nx) { // Note the difference
        data = new Item(d, s);
        next = nx;
    }
    ~Cell() {
        delete data;
        cerr << "  Deleting Cell " << "\n";
    }
};

//---------------------------------------------------------------------------
// Data structure class
class Row { // Interface class for one bar of the bargraph.
private:
    char label[10];       // Row header label
    Cell* head;           // Pointer to head of row

public:
    Row(int n);
    ~Row();
    void insert(char* name, int score); // delegation
    ostream& print(ostream& os) const;
};

//---------------------------------------------------------------------------
inline ostream& operator << (ostream& out, const Row& T) {
    return T.print(out);
}

//---------------------------------------------------------------------------
// A friend class can access private and protected members of other class in 
// which it is declared as friend.

//---------------------------------------------------------------------------
// Association is a relationship where all objects have their own lifecycle 
// and there is no owner.

// Aggregation is a specialised form of Association where all objects have 
// their own lifecycle, but there is ownership and child objects can not belong
// to another parent object.
