// Surprising example 3
// Try to compile this file using
// g++ -Wall -std=c++17 surprising-3.cpp

class A { protected: int x; };
class B : protected A {};     // protected derivation

int main() {
    A* ap;
    B* bp;
    ap = bp; // error: 'A' is an inaccessible base of 'B' 
}
