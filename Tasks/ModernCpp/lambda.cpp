/*
//...Lambda Function...

// Lambda functions in C++ (introduced in C++11) are anonymous functions that can be defined inline.
// They allow you to write short function - like expressions without formally defining a separate function.

//Syntax of Lambda Functions in C++...
//[ capture_list ] ( parameter_list ) -> return_type { function_body }
//Components:
//Capture list([]) : Specifies which variables from the surrounding scope can be accessed.
//Parameter list(()) : Defines the function parameters.
//Return type(->type) : Specifies the return type(optional, deduced automatically if omitted).
//Function body({}) : Contains the logic.

//2. Capture List in Lambda Functions
//The capture list determines how variables from the surrounding scope are accessed inside the lambda.

// Capture Method	                         Syntax                	Description
// Capture by Value                           [x]	     Captures x by value(creates a copy).
// Capture by Reference                       [&x]	     Captures x by reference(modifies original).
// Capture All by Value                       [=]	     Captures all local variables by value.
// Capture All by Reference                   [&]	     Captures all local variables by reference.
// Mixed Capture                              [x, &y]	 Captures x by value and y by reference.

// Advantages of Lambda Functions...

//✅ Shorter Code – Avoids writing separate function definitions.
//✅ Improved Readability – More concise and easier to understand.
//✅ Encapsulation – Keeps logic closer to where it’s used.
//✅ Higher - Order Functions – Allows functions to be passed as arguments easily.
//✅ Better Performance – Inline lambdas avoid function call overhead.

// Disadvantages of Lambda Functions...

//❌ A lambda cannot return a reference to a local variable because the variable goes out of scope when the lambda exits.
//❌ Complexity in Debugging – Debugging can be harder for complex lambda expressions.
//❌ Limited Reusability – Unlike named functions, lambdas are harder to reuse.
//❌ Verbose Syntax – Can become confusing with complicated captures and return types.
/*auto lambda = [](bool flag) {
    if (flag)
        return 10;   // int
    else
        return 3.14; // double (Error!)
};

std::cout << lambda(true);
*/

/*auto lambda = [](bool flag) -> double {
    if (flag)
        return 10;   // Implicitly converted to double
    else
        return 3.14;
};
*/

//❌ Lambdas without a capture list ([]) can be converted to function pointers, but lambdas with captures ([x]) cannot.
//❌ Since lambdas are often short-lived, dynamically allocated memory inside a lambda must be properly released, or memory leaks will occur.
// ✅ Fix: Use delete or smart pointers (std::unique_ptr).
//❌ std:: function issues
//❌ mutable issues with lambda function

/*int x = 10;
wrong way...
auto lambda = [x]() { x = 20; };  // ❌ Compilation error
correct way...
auto lambda = [x]() mutable { x = 20; };*/


//  Use Cases of Lambda Functions...

//✅ 1. Sorting with Custom Comparator Eg.:- sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
//✅ 2. Using Lambdas in std::for_each Eg.:- for_each(nums.begin(), nums.end(), [](int x) { std::cout << x * x << " "; });
//✅ 3. Callbacks in Multithreading (std::thread).
//✅ 4. Capturing External Variables.
/*#include <iostream>

int main() {
    int a = 5, b = 10;
    auto multiply = [a, b]() { return a * b; };
    std::cout << multiply() << std::endl; // 50
} */

//✅ 5. Filtering in STL Algorithms.
/*
#include <iostream>
using namespace std;

int main() {
    int x = 10, y = 20;

    // Capture by value
    auto lambda1 = [=]() { return x + y; };

    // Capture by reference
    auto lambda2 = [&]() { x++; y += x; };
    lambda1();
    cout << "After Lambda_1 Call x: " << x <<" y: " <<y<< endl;
    lambda2();
    cout << "After Lambda_2 Call x: " << x << " y: " << y << endl;
    return 0;
}
*/
#include<iostream>
#include<typeinfo>
using namespace std;
class unNamed{
    public:
    int operator()(int a,int b){
        return a+b;
    }
};
template<typename T,int size,typename callback>
void forEach(T(&arr)[size],callback operation){
    for(int i=0;i<size;i++){
        operation(arr[i]);
    }
}

// why offset is not incremented if pass by value but incremented if pass by refrence and if we want to increment it when pass by value we need to use mutable with it 
template<typename T>
class _unNamed{
    int offset;
    public:
  _unNamed(int off):offset(off){}
  void operator()(T& a){
    a+=offset;
    ++offset;
  }
};

int main(){
    // this lambda expression is automatically invoked as we call it 

    [](){
      cout<<"Inside the body of lambda expression"<<endl;
    }();
    
    // this is called when we make a call
    auto fn = [](){
        cout<<"Inside the body of lambda expression"<<endl;
    };
    fn();



    // lambda to add two numbers
    auto sum = [](int x,int y) noexcept{
       return x + y;
    };
    cout<<"sum is :"<<sum(5,2)<<endl;


    // proof that same is implemented as functor by compiler -> will perform the same operation using functor lets see
    unNamed u;
    cout<<"sum is :"<<u(5,2)<<endl;

//``````````````````````````````````````````````````````//
  
int arr[]{1,6,8,4,0};
forEach(arr,[](auto x){
   cout<<x<<" ";
});
cout<<endl<<endl;
// if we want to add offset to each value of array then
int offset = 5;
forEach(arr,[&](auto&x){
    x+=offset;
    offset++;
});
forEach(arr,[](auto x){
    cout<<x<<" ";
});

return 0;
}


/*
6 Pitfalls of Lambdas in C++ (With Examples)
Lambdas are powerful, but they come with potential pitfalls that can cause unexpected behavior or performance issues. Here are six common pitfalls:

1️⃣ Capturing by Reference Without Ensuring Lifetime
Lambdas capturing variables by reference do not extend their lifetime. If the variable goes out of scope, accessing it causes undefined behavior.

Example:
cpp
Copy
Edit
#include <iostream>
#include <functional>

std::function<void()> getLambda() {
    int x = 10;
    return [&]() { std::cout << x << "\n"; }; // ❌ Capturing `x` by reference
}

int main() {
    auto lambda = getLambda();  // x is destroyed when function exits
    lambda(); // ❌ Undefined behavior (accessing a dangling reference)
}
Fix: Capture by value instead:
cpp
Copy
Edit
return [x]() { std::cout << x << "\n"; }; // ✅ Capturing by value
2️⃣ Mutable Variables Not Updated in Capture
By default, lambda captures are read-only. Trying to modify captured values inside the lambda won’t work.

Example:
cpp
Copy
Edit
#include <iostream>

int main() {
    int x = 5;
    auto lambda = [x]() { x += 10; }; // ❌ x inside lambda is a copy, not modified outside
    lambda();
    std::cout << x; // Output: 5 (not 15)
}
Fix: Use the mutable keyword:
cpp
Copy
Edit
auto lambda = [x]() mutable { x += 10; };
3️⃣ Large Object Capture by Value (Performance Issue)
Capturing large objects by value creates unnecessary copies, which can impact performance.

Example:
cpp
Copy
Edit
#include <iostream>
#include <vector>

int main() {
    std::vector<int> largeVec(1'000'000, 42);
    
    auto lambda = [largeVec]() { // ❌ Creates a costly copy
        std::cout << largeVec.size();
    };
}
Fix: Capture by reference or use std::move if ownership is needed:
cpp
Copy
Edit
auto lambda = [&largeVec]() { std::cout << largeVec.size(); }; // ✅ Capture by reference
or

cpp
Copy
Edit
auto lambda = [vec = std::move(largeVec)]() { std::cout << vec.size(); }; // ✅ Move instead of copy
4️⃣ Dangling Reference from std::bind with Temporary Objects
Using std::bind with lambdas can lead to dangling references if a temporary variable is used.

Example:
cpp
Copy
Edit
#include <iostream>
#include <functional>

int main() {
    auto lambda = std::bind([](const int& x) { std::cout << x; }, 42); // ❌ Binding temporary
    lambda(); // ❌ Undefined behavior (dangling reference)
}
Fix: Pass values instead of references in std::bind:
cpp
Copy
Edit
auto lambda = std::bind([](int x) { std::cout << x; }, 42); // ✅ Pass by value
5️⃣ Unexpected Type Deduction Issues in Templates
Lambdas have unique types, which can cause issues in template functions expecting specific callable types.

Example:
cpp
Copy
Edit
#include <iostream>

template <typename Callable>
void callTwice(Callable func) {
    func();
    func();
}

int main() {
    auto lambda = [] { std::cout << "Hello\n"; };
    callTwice(lambda); // ✅ Works

    callTwice([] { std::cout << "World\n"; }); // ❌ Error: different types for each lambda
}
Fix: Use std::function to store lambda:
cpp
Copy
Edit
void callTwice(std::function<void()> func) { func(); func(); }
6️⃣ Unnecessary Heap Allocation for std::function
When assigning lambdas to std::function, heap allocation occurs if the lambda is too large.

Example:
cpp
Copy
Edit
#include <iostream>
#include <functional>

int main() {
    std::function<void()> func = [bigArray = std::vector<int>(1'000'000)]() {
        std::cout << "Using big array\n";
    }; // ❌ May cause heap allocation

    func();
}
Fix: Use auto or explicitly optimize memory usage:
cpp
Copy
Edit
auto lambda = [bigArray = std::vector<int>(1'000'000)]() { std::cout << "Optimized\n"; }; // ✅ No heap allocation
🔹 Conclusion
Lambdas are powerful, but misuse can lead to performance issues or undefined behavior.
To avoid pitfalls: ✔ Ensure correct capture (value vs reference)
✔ Use mutable for modifying captured values
✔ Avoid unnecessary copies
✔ Watch out for lifetime issues
✔ Prefer auto over std::function for performance
*/