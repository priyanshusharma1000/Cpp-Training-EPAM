/*
Variadic Templates in C++

Variadic templates allow functions or classes to accept a variable number of template arguments. They provide a powerful mechanism for creating flexible and generic code.

*/

/*
Syntax

A variadic template has at least one named parameter, followed by an ellipsis (...), which represents zero or more additional template parameters.


Example of a Variadic Template Function

#include <iostream>

// Base case: Stop recursion when there are no arguments left
void print() {
    std::cout << std::endl;
}

// Recursive variadic function
template <typename T, typename... Args>
void print(T first, Args... rest) {
    std::cout << first << " ";
    print(rest...);  // Recursively call print() with remaining arguments
}

int main() {
    print(1, 2.5, "priyanshu", 'S');//1 2.5 priyanshu S
    return 0;
}
*/

// Variadic Class Template
#include <iostream>

// Variadic class template
template <typename... Args>
class Tuple {};

// Specialization for at least one argument
template <typename T, typename... Rest>
class Tuple<T, Rest...> {
public:
    T first;
    Tuple<Rest...> rest;

    Tuple(T f, Rest... r) : first(f), rest(r...) {}

    void print() {
        std::cout << first << " ";
        rest.print();
    }
};

// Base case specialization
template <>
class Tuple<> {
public:
    void print() {}
};

int main() {
    Tuple<int, double, char> t(1, 2.5, 'A');
    t.print();  // Output: 1 2.5 A
    return 0;
}
