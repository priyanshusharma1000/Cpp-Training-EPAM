//A functor (function object) in C++ is a class or struct that overloads the operator(), making an instance of the class behave like a function. Essentially, it allows objects to be invoked as if they were functions.

/*
Why Use Functors?
State Maintenance: Unlike regular functions, functors can maintain state across multiple calls.

Custom Operations: They allow for more flexibility than function pointers by enabling encapsulated logic.

Performance Optimization: The compiler can inline functor calls, potentially making them faster than function pointers.

Better Readability: Functors make the code cleaner and more modular.
*/


/*
#include <iostream>

class MultiplyBy {
    int factor;
public:
    MultiplyBy(int f) : factor(f) {}
    
    // Overloading operator()
    int operator()(int x) {
        return x * factor;
    }
};

int main() {
    MultiplyBy times2(2);  // Creating a functor object
    MultiplyBy times5(5);  // Another functor with a different factor

    std::cout << "2 * 3 = " << times2(3) << std::endl; // Output: 6
    std::cout << "5 * 4 = " << times5(4) << std::endl; // Output: 20

    return 0;
}
*/

//Functors are widely used in the STL algorithms (e.g., std::sort, std::for_each, etc.).

#include <iostream>
#include <vector>
#include <algorithm>

class CompareDescending {
public:
    bool operator()(int a, int b) {
        return a > b; // Sorting in descending order
    }
};

int main() {
    std::vector<int> vec = {4, 1, 3, 9, 7};

    // Using functor to sort in descending order
    std::sort(vec.begin(), vec.end(), CompareDescending());

    for (int num : vec) {
        std::cout << num << " ";
    }
    return 0;
}
