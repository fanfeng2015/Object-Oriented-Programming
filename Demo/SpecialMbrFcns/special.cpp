#include <iostream>
using namespace std;

// Macro to print and then run a line of source code
#define v(a) cout << "\n["#a"]" << endl; \
             a

// Macro to print a variable
#define p(a) #a" = " << a

//--------------------------------------------------------------------
class T {
private:
    int x;
    int* a = new int[3];

public:
    // Default constructor
    T() : x(0), a(nullptr) {
        cout << "  Null constructor" << endl;
    }

    // Destructor
    ~T() {
        delete[] a;
        cout << "  Destructor" << endl;
    }
    
    // Constructor from an int. Explicit inhibits it from being used
    // implicitely to convert an int to T.
    explicit T(int x) : x(x) {
        cout << "  Explicit constructor T(" << x << ")" << endl;
    }

    // Copy constructor
    T(const T& rhs) : x( rhs.x ), a( rhs.a ) {
        cout << "  Copy constructor" << endl;
    }

    // Move constructor
    T(T&& rhs) : x( rhs.x ), a( rhs.a ) {
        if (this != &rhs) rhs.a = nullptr;
        cout << "  Move constructor" << endl;
    }

    // Copy assignment
    T& operator = ( const T& rhs ) {
        x = rhs.x;
        a = rhs.a;
        cout << "  Copy assignment" << endl;
        return *this;
    }

    // Move assignment
    T& operator = ( T&& rhs ) {
        if (this != &rhs) {
            x = rhs.x;
            delete[] a;
            a = rhs.a;
            rhs.a = nullptr;
        }
        cout << "  Move assignment" << endl;
        return *this;
    }

    ostream& print( ostream& out ) const {
        return out << "(" << x << ", " << a << ")";
    }
};

//--------------------------------------------------------------------
// Extend operator << () to type T objects
inline
ostream& operator << ( ostream& out, T& val ) { return val.print(out); }

//--------------------------------------------------------------------
int main(void) {
    v( T a; )            // null constructor
    cout << "  " << p( a ) << endl;
    // v( T b = 17; )    // error because of explicit keyword
    v( T b(17); )        // explicit constructor
    cout << "  " << p( b ) << endl;
    v( T c(b); )         // copy constructor
    cout << "  " << p( c ) << endl;
    v( T d( move(b) ); ) // move constructor
    cout << "  " << p( d ) << ", " << p( b ) << endl;
    v( T e; )            // null constructor
    cout << "  " << p( e ) << endl;
    v( e = b; )          // copy assignment
    cout << "  " << p( e ) << endl;
    v( T f; )            // null constructor
    cout << "  " << p( f ) << endl;
    v( f = move(d); )    // move assignment
    cout << "  " << p( f ) << ", " << p( d ) << endl;
    v( T g = T(41); )    // explicit constructor
    cout << "  " << p( g ) << endl;
    v( T h; )            // null constructor
    cout << "  " << p( g ) << endl;
    v( h = T(89); )      // explicit constructor & move assignment
    cout << "  " << p( h ) << endl;

    cout << endl;
    return 0;
}
