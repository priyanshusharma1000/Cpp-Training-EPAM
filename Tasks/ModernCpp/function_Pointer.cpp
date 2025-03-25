/*
A function pointer in C++ is a pointer that stores the address of a function. This allows functions to be invoked indirectly, providing flexibility in code execution.
*/



/*
return_type (*pointer_name)(parameter_list);
*/


/*
int (*funcPtr)(int, int);  // Function pointer to a function returning int and taking two int parameters
*/

/*
Function pointers are useful in scenarios where we need dynamic function calls, such as:

Callback Mechanisms – Useful in event handling, GUI applications, or asynchronous programming.

Passing Functions as Arguments – Allows functions to be passed dynamically to other functions.

Jump Tables / Function Tables – Efficient implementation of switch-case scenarios.

Polymorphism in C (Before C++ Inheritance) – Alternative to virtual functions.
*/

/*
#include <iostream>
using namespace std;

// Two simple functions
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int main() {
    // Function pointer declaration
    int (*funcPtr)(int, int);

    // Assign add function to pointer
    funcPtr = add;
    cout << "Addition: " << funcPtr(5, 3) << endl;  // Calls add(5, 3)

    // Assign multiply function to pointer
    funcPtr = multiply;
    cout << "Multiplication: " << funcPtr(5, 3) << endl;  // Calls multiply(5, 3)

    return 0;
}
*/
/*
Function pointer in arrays
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

// Array of function pointers
int (*operations[2])(int, int) = {add, subtract};

int main() {
    int choice, x = 10, y = 5;
    
    cout << "Enter 0 for addition, 1 for subtraction: ";
    cin >> choice;

    cout << "Result: " << operations[choice](x, y) << endl; // Calls add or subtract dynamically
    return 0;
}
*/



//```````` Callback Function```````` //
//A callback function is a function that is passed as an argument to another function and is executed later in response to an event or condition.


/*
#include<iostream>
using namespace std;

int add(int a,int b){
    return a+b;
}

void compute(int x,int y,int(*callback)(int ,int)){
    cout<<"Result :"<<callback(x,y)<<endl;
}
int main(){
    compute(5,10,add);
    return 0;
}
*/

// Callbacks for Sorting (like qsort)

/*
#include <iostream>
#include <algorithm>
using namespace std;

// Comparison function (callback for sorting)
bool descending(int a, int b) {
    return a > b;  // Sort in descending order
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, size);

    // Sort using function pointer as a callback
    sort(arr, arr + size, descending);

    cout << "After sorting: ";
    printArray(arr, size);

    return 0;
}
Explanation: sort() calls descending() as a comparison function.
*/


/*
Callbacks Using std::function (Modern Approach)
C++11 introduces std::function and std::bind for more flexibility in callbacks.

#include <iostream>
#include <functional>
using namespace std;

// Function that takes a callback (using std::function)
void executeCallback(function<void()> callback) {
    cout << "Executing callback: ";
    callback();
}

int main() {
    auto greet = []() { cout << "Hello from Lambda!" << endl; };
    executeCallback(greet);  // Passing a lambda as a callback
    return 0;
}

*/

/* another type of writing 

#include<iostream>
using namespace std;
using comp = int(*)(int,int);
int add(int a,int b)
{
    return a+b;
}
void compute(int x,int y,comp callback){
    cout<<"Result: "<<callback(x,y);
}

int main(){
    compute(5,6,add);
   return 0;
}
*/
/*
#include <iostream>
#include <functional>
using namespace std;
int add(int a,int b){
    return a+b;
}
// below two lines do the exactly same task but the first one is only valid for functions,lamdas,functors 
// and second one is valid for lambdas without capture list and valid for functions and functors
//function<int(int,int)>callback
//int (*callback)(int ,int)
int compute(int x,int y,int (*callback)(int ,int)){
    return callback(x,y);
}
int main(){
    cout<<compute(2,3,add);
}
*/


#include<iostream>
using namespace std;

using comparator = bool(*)(int,int);

template<typename T,int size>



bool cmp(int a,int b){
    return a>=b;
}
bool cmp1(int a,int b){
    return a<=b;
}


class cmp2{
    public:
    bool operator()(int a,int b){
        return a<=b;    
    }
};
template<typename T1,typename T2,int size>
void Sort(T1(&arr)[size],T2 cmp3){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){
            if(cmp3(arr[j],arr[j+1])){ // one line that decide whether sorting is done in ascending order or descending order so rather than creating different different function for ascending and descending sorting we create a function pointer and made decision based on it 
                T1 temp = move(arr[j]);
                arr[j] = move(arr[j+1]);
                arr[j+1] = move(temp);
            }
        }
    }
}
// if we have to do sorting for string then we will make a compare function which will do the comparision based on string value

int main(){

int arr[]{1,6,8,4,0};

for(auto x:arr){
cout<<x<<" ";
}
cout<<endl;


Sort(arr,cmp2());

for(auto x:arr){
    cout<<x<<" ";
}
return 0;
}
