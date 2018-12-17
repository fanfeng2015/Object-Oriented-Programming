/*
 *  virtual.hpp
 *  Virtual
 *  Created by Alice Fischer on 3/31/09.
 */
#include <iostream>

using namespace std;

class Basic {
public:
    virtual ~Basic() {}
    virtual void print() { cout << "I am basic. "; }
};

class Virtual : public Basic {
public:
    virtual void print() { cout << "I have virtual. "; }
};

class Question : public Virtual {
public:
    virtual void print() { cout << "I am questing. "; }
};
