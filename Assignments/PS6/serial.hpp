// -*- mode: c++; tab-width: 4 -*-
// File: serial.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 6

#ifndef SERIAL_HPP_
#define SERIAL_HPP_

#include "tools.hpp"

// ------------------------------------------------------------------------------
// Singleton class for generating unique ID's

class Serial {
private:
   int nextUID = 1;          // data member for next UID to be assigned

   static Serial* Sobj;      // pointer to singleton Serial object

   static Serial* uidGen() { // instaniates Serial on first call
      if (Sobj == nullptr) { Sobj = new Serial; }
      return Sobj;
   }
   
   Serial() = default;       // private constructor prevents external instantiation

public:
   static int newID() { return uidGen()->nextUID++; }
};

#endif /* SERIAL_HPP_ */
