// Topic name : Namespace in cpp
//This is file is created by Priyanshu sharma

#include <iostream>

// Defining a custom namespace
namespace FirstNamespace {
    void display() {
        std::cout << "Inside FirstNamespace" << std::endl;
    }
}

// Another namespace
namespace SecondNamespace {
    void display() {
        std::cout << "Inside SecondNamespace" << std::endl;
    }
}

int main() {
    // Calling functions using namespace resolution operator
    FirstNamespace::display();
    SecondNamespace::display();

    // Using namespace directive (not recommended for large projects)
    using namespace FirstNamespace;
    display();  // Calls FirstNamespace::display()
    
    return 0;
}
