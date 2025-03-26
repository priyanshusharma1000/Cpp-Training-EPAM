#include "my_class.h"
#include <iostream>

class MyClass_Impl // the actual implementation
{
public:
    void some_method()
    {
        std::cout << "Implementation method called!\n";
    }
};

MyClass::MyClass() : pimpl(new MyClass_Impl()) {} // constructor

MyClass::~MyClass() { delete pimpl; } // destructor

void MyClass::some_method()
{
    pimpl->some_method(); // delegation to the implementation
}

int main(){
    MyClass m1;
    m1.some_method();
    return 0;
}