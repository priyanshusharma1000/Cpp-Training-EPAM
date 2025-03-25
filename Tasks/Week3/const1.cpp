// Topic Name : const object and non const object of class with const member function and non const member function of class
//This file is created by: Priyanshu Sharma

/*
In a non-const member function, the this pointer is ClassName* const this, meaning it points to the current object and can modify data members.

In a const member function, the this pointer is const ClassName* const this, meaning it points to a constant object, so no modification is allowed.

A const object can only call const member functions, ensuring that data remains read-only. It can be initialized only through a constructor.

A const member function cannot modify members (except mutable ones). If a non-const object calls a const function, it follows the read-only rule and does not modify data.
*/

/*
1️⃣ Const Object (const ClassName obj;)
✅ Can call only const member functions
❌ Cannot call non-const member functions
✅ Can be initialized only through the constructor
❌ Cannot modify its data members after initialization


2️⃣ Non-Const Object (ClassName obj;)
✅ Can call both non-const and const member functions
✅ Can modify data members using non-const functions
✅ Can read data members using const functions

*/

#include <iostream>
using namespace std;

class Demo {
private:
    int x;
    mutable int y; // `mutable` allows modification even in `const` functions

public:
    // Constructor
    Demo(int val1, int val2) : x(val1), y(val2) {}

    // Non-const member function: Can modify data
    void setValue(int val) {
        x = val;
        cout << "setValue() called, x modified to: " << x << endl;
    }

    // Const member function: Cannot modify non-mutable members
    int getValue() const {
        // x = 20;  // ❌ ERROR: Cannot modify x inside const function
        cout << "getValue() called (Read-Only Function)\n";
        return x;
    }

    // Const member function modifying `mutable` member
    void modifyMutable() const {
        y++;  // ✅ Allowed because `y` is mutable
        cout << "modifyMutable() called, y modified to: " << y << endl;
    }
};

int main() {
    // 1️⃣ Non-const object: Can call both const & non-const functions
    Demo obj1(10, 100);
    cout << "Initial value of obj1: " << obj1.getValue() << endl;
    obj1.setValue(20);  // ✅ Allowed: Modifies x
    obj1.modifyMutable();  // ✅ Allowed: Modifies y (mutable)
    
    cout << endl;

    // 2️⃣ Const object: Can call only const functions
    const Demo obj2(30, 200);
    cout << "Value of obj2: " << obj2.getValue() << endl;  // ✅ Allowed (const function)
    
    // obj2.setValue(40);  // ❌ ERROR: Can't modify x in a const object
    obj2.modifyMutable();  // ✅ Allowed: Modifies y (mutable)

    return 0;
}
