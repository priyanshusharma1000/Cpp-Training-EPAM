#include <iostream>
#include <vector>
#include<functional>
using namespace std;
/*
Syntax of Lambda Returning Lambda
auto outerLambda = []() {
    return []() {
        std::cout << "Hello from inner lambda!" << std::endl;
    };
};
The outer lambda returns an inner lambda.

Calling outerLambda() will return a function, which we can call separately.

#include <iostream>

int main() {
    auto outerLambda = []() {
        return []() {
            std::cout << "Hello from inner lambda!" << std::endl;
        };
    };

    auto innerLambda = outerLambda(); // Returns the inner lambda
    innerLambda(); // Calls the inner lambda

    return 0;

	Hello from inner lambda!
}

#include <iostream>

int main() {
    auto multiply = [](int factor) {
        return [factor](int num) { return num * factor; };
    };

    auto doubleIt = multiply(2); // Returns a lambda that multiplies by 2
    auto tripleIt = multiply(3); // Returns a lambda that multiplies by 3

    std::cout << doubleIt(5) << std::endl; // 10
    std::cout << tripleIt(5) << std::endl; // 15

    return 0;
}
Returning a Lambda from a Function
Instead of defining lambdas inline, we can use functions to return lambdas.

#include <iostream>
#include <functional> // For std::function

std::function<int(int)> getMultiplier(int factor) {
    return [factor](int x) { return x * factor; };
}

int main() {
    auto multiplyBy5 = getMultiplier(5);
    std::cout << multiplyBy5(10) << std::endl; // 50
    return 0;
}


*/
int main()
{    //q) what if we dont specify return type of lambada in the below code case
	//Each lambda expression has a unique, compiler-generated type. This means:
   //The switch cases return different lambda objects, each with a different type.
  //Since auto requires all return values to have the same type, this results in a type mismatch error.


    /*
	Solution 1: Use std::function<> (Recommended)
    The best way to fix this issue is by using std::function<>, which allows storing different lambdas with the same signature.
		auto calcLam = [](int choice)->function<int(int,int)>
	{
		switch (choice)
		{
		case 1:
			return [] (int a, int b){ return a + b; };
			break;
		case 2:
			return [](int a, int b){ return a - b; };
			break;
		case 3:
			return [](int a, int b){ return a * b; };
			break;
		}
		return [](int , int )->int { return 0; };
	};

 
	auto operation = calcLam(3); // Get the operation lambda (function pointer)
	int result = operation(10, 20); // Use it
	cout<<result;
	return 0;

//Why does this work?
std::function<int(int, int)> ensures a common return type, allowing different lambdas to be stored.



Solution 2: Use auto but Explicitly Specify Return Type
Instead of auto, use decltype to enforce consistent return type.

#include <iostream>
using namespace std;

int main() {
    auto calcLam = [](int choice) -> decltype([](int a, int b) { return a + b; }) {
        switch (choice) {
        case 1:
            return [](int a, int b) { return a + b; };
        case 2:
            return [](int a, int b) { return a - b; };
        case 3:
            return [](int a, int b) { return a * b; };
        }
        return [](int, int) { return 0; }; // Default case
    };

    auto operation = calcLam(2); // Get the subtraction lambda
    int result = operation(10, 20); // Use it
    cout << result; // Output: -10

    return 0;
}
Why does this work?
decltype([](int a, int b) { return a + b; }) ensures that all lambdas return the same type.

 Key Takeaways
Each lambda has a unique type, causing a mismatch in return types.

Use std::function<> if lambdas have a common signature.

Use decltype() to infer and enforce a consistent return type.

*/


	auto calcLam = [](int choice)->function<int(int,int)>
	{
		switch (choice)
		{
		case 1:
			return [] (int a, int b){ return a + b; };
			break;
		case 2:
			return [](int a, int b){ return a - b; };
			break;
		case 3:
			return [](int a, int b){ return a * b; };
			break;
		}
		return [](int , int )->int { return 0; };
	};

 
	auto operation = calcLam(3); // Get the operation lambda (function pointer)
	int result = operation(10, 20); // Use it
	cout<<result;
	return 0;
}