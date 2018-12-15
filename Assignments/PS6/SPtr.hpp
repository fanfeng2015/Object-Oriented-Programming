// -*- mode: c++; tab-width: 4 -*-
// File: SPtr.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 6

#ifndef SPTR_HPP_
#define SPTR_HPP_

#include <iostream>
#include <exception>

#include "serial.hpp"

using namespace std;

// ----------------------------------------------------------------------------
// Smart pointer exception class
class SPexception : std::exception {
private:
    string s;
public:
    SPexception(string s) : s(s) {}
    virtual const char* what() const noexcept { return s.data(); }
};

// Resolve circular dependency (need to include block.hpp in SPtr.cpp)
class Block; // forward decleration, telling compiler Block is a type
using T = Block;

// ----------------------------------------------------------------------------
// Smart pointer class
class SPtr {
private:
    unsigned* count = 0;    // shared count among all SPtr with same target
    T* target = nullptr;    // shared target

public:
    // Default constructor
    SPtr();
    // Construct an SPtr to manage p
    SPtr(T* p);
    // Copy constructor
    SPtr(const SPtr& sp);
    // Copy assignment
    SPtr& operator=(const SPtr& sp);
    // Move constructor
    SPtr(SPtr&& sp);
    // Move assignment
    SPtr& operator=(SPtr&& sp);
    // Destructor
    ~SPtr() {
        reset();
    }

    bool empty() const { return count == nullptr; }
    void reset();

    // Return the shared target
    T* tar() const { return target; }

    // Follow operator
    T& operator*() {
        if (!empty()) return *target;
        else throw SPexception("Can't follow empty SPtr");
    }
};

#endif /* SPTR_HPP_ */

/*

class Block {
    SPtr ...;
}

class SPtr {
    class Block; // forward decleration
    using T = Block;
    Block* bp; // okay

    ~SPtr() {
        // not okay
        // this doesn't delete the pointer, but deletes the stuff that the pointer points to
        // solution: move the destructor to .cpp file, and #include block.hpp in SPtr.cpp
        delete* bp;
    }
}

*/
