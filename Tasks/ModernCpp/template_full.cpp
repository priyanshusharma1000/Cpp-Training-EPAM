#include<iostream>
// function template
/*
template<typename T,typename U>
auto add(T a,U b)
{
    return a+b;
}
int main(){
  std::cout<<add(4,7)<<std::endl;
  return 0;
}
*/

//class template
/*
template<typename T>
class stack{
    T arr[100];
    int top = -1;
    public:
    void push(T val){
        arr[++top] = val;
    }
    T pop(){
        return arr[top--];
    }
}
Works for int, double, string, etc.
Real-World Use Case
STL Containers like std::vector<T> and std::map<T, U>.
*/


// template specialization
/*
Why is specialization needed?
Sometimes, a generic template does not work efficiently for all types.

(1)Partial Specialization
Modifies some behavior while keeping the base template.

Imagine we are designing a Database Storage System where we need to store different data types efficiently.

Generic template: Works for all types.

Partial specialization: Optimizes storage for std::string by using dynamic memory allocation instead of direct object storage.

#include <iostream>
#include <cstring>

// 🔷 Generic Storage Template
template <typename T>
class Storage {
    T data;
public:
    Storage(T val) : data(val) {}
    void show() { std::cout << "Stored Data: " << data << "\n"; }
};

// 🔷 Partial Specialization for `std::string`
template <>
class Storage<std::string> {
    char* data;
public:
    Storage(std::string val) {
        data = new char[val.length() + 1];
        std::strcpy(data, val.c_str());
    }
    void show() { std::cout << "Stored String: " << data << "\n"; }
    
    ~Storage() { delete[] data; }  // Free allocated memory
};

int main() {
    Storage<int> intStore(42);
    intStore.show();  // Outputs: Stored Data: 42

    Storage<std::string> stringStore("Hello Templates");
    stringStore.show();  // Outputs: Stored String: Hello Templates

    return 0;
}
🔹 Why is Partial Specialization Useful Here?
🔹 The generic template works fine for int, double, etc.
🔹 But for std::string, direct storage wastes memory (due to SSO optimizations in modern C++).
🔹 Partial specialization ensures dynamic allocation for efficiency.






``````````````````````SSO OPTIMIZATION````````````````````
Small String Optimization (SSO) is an optimization technique used by modern C++ std::string implementations to avoid heap allocations for small strings.

How std::string Normally Works?
In older implementations (before SSO was common), std::string always allocated memory on the heap when storing data.
For example:
std::string s1 = "Hello";
std::string s2 = "This is a long string";

Before SSO:
Both s1 and s2 allocate memory on the heap.
Even small strings incur a heap allocation overhead.

How Does SSO Work?
Modern C++ standard libraries (like GCC, Clang, MSVC) store small strings inside the string object itself, without heap allocation.

Typically, strings up to 15 characters (implementation-dependent) are stored directly inside the object, avoiding heap allocation.

std::string s = "Short";  // Stored inside the std::string object (No heap allocation)
std::string s = "This is a very long string that requires heap allocation";  // Stored in heap



💡 Internally, std::string consists of:
A char buffer inside the object (for small strings).
A pointer to heap memory (for large strings).
A size and capacity tracker.



 Why Does Direct Storage of std::string Waste Memory?
If we store std::string directly in a class without using a pointer, we always allocate the full-size std::string object even when it's not needed.

Example (Inefficient Storage)
class Storage {
    std::string data;
public:
    Storage(std::string val) : data(val) {}
    void show() { std::cout << "Stored String: " << data << "\n"; }
};
Here, std::string always reserves memory for its internal SSO buffer, even if we don't use it.

Extra space is wasted when we store many small strings.


🔥 Interview Question Insights
1️⃣ What is Small String Optimization (SSO)?
SSO is an optimization in modern std::string implementations that stores small strings inside the object instead of allocating heap memory.

2️⃣ Why does direct std::string storage waste memory?
Because std::string reserves space for its SSO buffer, even when unnecessary, leading to wasted memory for small strings.

3️⃣ When should you use dynamic allocation instead of std::string?
When handling multiple small strings or optimizing for memory in embedded systems.



Why Does std::string Reserve Extra Space?
Even if a std::string object contains an empty string (""), it still reserves memory for its internal SSO buffer.
#include <iostream>
#include <string>

int main() {
    std::string emptyStr;  
    std::string smallStr = "Hi";  
    std::string longStr = "This is a long string that exceeds SSO";

    std::cout << "Empty String Capacity: " << emptyStr.capacity() << "\n";
    std::cout << "Small String Capacity: " << smallStr.capacity() << "\n";
    std::cout << "Long String Capacity: " << longStr.capacity() << "\n";

    return 0;
}


Empty String Capacity: 15  
Small String Capacity: 15  
Long String Capacity: 34  

Even when emptyStr is empty, it still has a capacity of 15, meaning it reserves 15 bytes of memory.

smallStr = "Hi" also reserves 15 bytes, even though it only needs 3 bytes (H, i, and \0).

🔷 Why is This an Issue?
If you store a large number of small strings, this extra reserved space per object accumulates and wastes memory.

*/





// full specialization


/*
Real-World Use Case: Boolean Data Compression

Imagine a scenario where we want to store boolean values efficiently.

Generic template stores values normally.

Full specialization optimizes bool storage using bit manipulation instead of using sizeof(bool) = 1 byte.

#include <iostream>
#include <bitset>

// 🔷 Generic Storage Template
template <typename T>
class Storage {
    T data;
public:
    Storage(T val) : data(val) {}
    void show() { std::cout << "Stored Data: " << data << "\n"; }
};

// 🔷 Full Specialization for `bool`
template <>
class Storage<bool> {
    std::bitset<1> data;  // Uses only 1 bit instead of 1 byte
public:
    Storage(bool val) : data(val) {}
    void show() { std::cout << "Stored Boolean: " << (data.test(0) ? "True" : "False") << "\n"; }
};

int main() {
    Storage<int> intStore(100);
    intStore.show();  // Outputs: Stored Data: 100

    Storage<bool> boolStore(true);
    boolStore.show();  // Outputs: Stored Boolean: True

    return 0;
}

Why is Full Specialization Useful Here?
🔹 The generic template stores 1 bool = 1 byte (wasteful).
🔹 Full specialization reduces storage to 1 bit, which is crucial for memory-constrained systems (e.g., embedded devices).
🔹 Bit manipulation ensures maximum efficiency.
*/


/*
interview Questions & Insights
Q: When would you use partial specialization over full specialization?
A: Use partial specialization when you only need to modify part of the behavior, while full specialization is needed for complete replacement.

Q: Why is std::bitset used in full specialization for bool?
A: It saves memory by using only 1 bit instead of 1 byte per boolean.

Q: Can you specialize a member function instead of the entire class?
A: Yes, member function specialization is possible if only one function needs to be changed.
*/

/*
Final Thoughts
✔ Partial specialization is great for handling special cases while keeping generic behavior intact.
✔ Full specialization is powerful when entirely different logic is needed for a specific type.
✔ Used extensively in STL, memory optimization, and embedded systems.
*/




//Variadic Templates
/*
Variadic templates were introduced in C++11 to allow templates to accept a variable number of arguments. Before variadic templates, we had to manually overload templates for different numbers of parameters, which was inefficient.

Problem Before Variadic Templates
Before C++11, we had to write multiple template specializations for different numbers of arguments:

template <typename T1>
void print(T1 t1) {
    std::cout << t1 << "\n";
}

template <typename T1, typename T2>
void print(T1 t1, T2 t2) {
    std::cout << t1 << " " << t2 << "\n";
}

// More overloads required for 3, 4, 5 parameters...

Issue: This approach does not scale as the number of parameters increases.

Variadic Template Syntax
A variadic template uses an ellipsis (...) to accept an arbitrary number of template arguments.


 Example: Print Any Number of Arguments
#include <iostream>

// Base case: No arguments left
void print() {
    std::cout << "\n";
}

// Variadic template function
template <typename T, typename... Args>
void print(T first, Args... rest) {
    std::cout << first << " ";
    print(rest...);  // Recursively call with remaining arguments
}

int main() {
    print(1, 2.5, "Hello", 'A');
    return 0;
}


Expanding Parameter Packs (sizeof...)
We can determine how many arguments are left using sizeof...

template <typename... Args>
void countArgs(Args... args) {
    std::cout << "Number of arguments: " << sizeof...(args) << "\n";
}

int main() {
    countArgs(1, 2, 3, "Hello");
    countArgs(42);
    return 0;
}
Number of arguments: 4
Number of arguments: 1
sizeof...(args) returns the number of arguments in the parameter pack


🔷 Fold Expressions (C++17)
Before C++17, we used recursion for variadic templates. Fold expressions simplify this.

Example: Sum of All Arguments

template <typename... Args>
auto sum(Args... args) {
    return (args + ...);  // Fold expression
}

int main() {
    std::cout << sum(1, 2, 3, 4, 5) << "\n";  // Output: 15
    return 0;
}


✅ How It Works:
Equivalent to:
(((1 + 2) + 3) + 4) + 5

📌 Types of Fold Expressions:

(args + ...) → Left fold ((((a + b) + c) + d))

(... + args) → Right fold ((a + (b + (c + d))))

🔹 No recursion needed!




Real-World Use Case of Variadic Templates
1️⃣ Logging System
#include <iostream>

void logMessage() {
    std::cout << "\n";
}

template <typename T, typename... Args>
void logMessage(T first, Args... rest) {
    std::cout << first << " ";
    logMessage(rest...);
}

int main() {
    logMessage("[INFO]", "User", "logged in at", 10, "PM");
    return 0;
}

[INFO] User logged in at 10 PM
 Works with any number of arguments, removing manual overloads.

*/

// varaidic class template -> tuple container implementation
/*
#include <iostream>
using namespace std;
 
// Variadic template class
template<typename... Args>
class MyClass;
 
// Specialization for handling the first type
template<typename First,typename...Args>

class MyClass<First,Args...>{
    public:
    First data;
    MyClass<Args...> next;
    MyClass(First val1,Args... val2):data(val1),next(val2...){}
    void print(){
        cout<<data<<" ";
        next.print();
    }
};
 
template<>
class MyClass<>{
    public:
    void print(){}
};
 
int main() {
    MyClass<int, string, double> obj(10, "hello", 3.14);
    obj.print();
    return 0;
}
*/


// template metaprogramming

