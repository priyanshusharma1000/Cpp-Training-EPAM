/*
C-Style Casting in C++

C-style casting is the traditional method of type conversion in C and C++. It is performed using the syntax:

(type) expression
      or
type(expression)

Importance of C-Style Casting

Simplicity: It is concise and easy to write.
Backward Compatibility: C++ retains C-style casting for compatibility with older C code.
Allows Implicit Conversions: Can be used for both built-in and user-defined types.


Where is C-Style Casting Used?
Converting fundamental data types
Casting void pointers to specific types
Interfacing with legacy C libraries
performance-sensitive applications where runtime type checks are not needed

Example 1: Converting between fundamental data types
#include <iostream>
using namespace std;

int main() {
    double pi = 3.14159;
    int int_pi = (int) pi;  // C-style cast
    cout << "Original: " << pi << ", After Casting: " << int_pi << endl;//Original: 3.14159, After Casting: 3
    return 0;
}




Loopholes and Problems in C-Style Casting
C-style casting has several drawbacks that make it unsafe:

(1)No Type Safety
C-style casting does not check whether a conversion is valid at compile-time.

#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class" << endl; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived class" << endl; }
};

int main() {
    Base* base = new Base();
    Derived* derived = (Derived*) base;  // C-style cast (Unsafe!)
    derived->show();  // Undefined behavior
    delete base;
    return 0;
}
 Issue: No type safety—if base is not actually a Derived object, calling derived->show() can result in undefined behavior.

(2) Doesn't Differentiate Between Cast Types
C++ provides four safer casting operators:
static_cast
dynamic_cast
const_cast
reinterpret_cast
A C-style cast performs all of them, making it dangerous.



*/