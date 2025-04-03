/*
Understanding push_back vs emplace_back in C++ STL
Both push_back() and emplace_back() are used to add elements to the end of a std::vector. However, emplace_back() is preferred over push_back() when constructing objects because it avoids unnecessary temporary objects and extra copying/moving.


Feature	                             push_back(value)	                                   emplace_back(args...)
Accepts:	                    Pre-existing object or temporary object	                Arguments to construct an object inplace
Performance:	            May involve an extra copy/move	                       Directly constructs the object in place (moreefficient)
Temporary Object Creation:	Yes, if a temporary object is passed	               No, constructs in-place
Best Used For:	            Simple data types like int, double, char	    Complex objects like std::pair, std::tuple, or custom classes

*/
#include <iostream>
#include <vector>
using namespace std;

class Demo {
public:
    int x, y;
    
    // Constructor
    Demo(int a, int b) : x(a), y(b) {
        cout << "Constructor Called for (" << x << ", " << y << ")\n";
    }

    // Copy Constructor
    Demo(const Demo& other) {
        x = other.x;
        y = other.y;
        cout << "Copy Constructor Called for (" << x << ", " << y << ")\n";
    }

    // Move Constructor
    Demo(Demo&& other) noexcept{
        x = other.x;
        y = other.y;
        cout << "Move Constructor Called for (" << x << ", " << y << ")\n";
    }
};

int main() {
    vector<Demo> v1, v2;

    cout << "\nUsing push_back:\n";
    Demo obj1(1, 2);
    v1.push_back(obj1);   // Copy constructor is called
    v1.push_back(Demo(3, 4)); // Temporary object → Move constructor

    cout << "\nUsing emplace_back:\n";
    v2.emplace_back(5, 6); // Directly constructs in place
    v2.emplace_back(7, 8); // No extra move or copy

    return 0;
}
