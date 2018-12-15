// -*- mode: c++; tab-width: 4 -*-
// File: main.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 6

#include "driver.hpp"

void run();

int main() {
    banner();
    run();
    bye();
}

// Instantiate Driver and call begin().
void run() {
	Driver driver; // Driver diver(); // not okay since this declares a function instead of on object
	driver.begin();
}
