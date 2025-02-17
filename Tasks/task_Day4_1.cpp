//This file is created by Priyanshu Sharma
#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0) // Base case
        return 1;
    else
        return n * factorial(n - 1); // Recursive case
}

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) return 0; // Base case
    if (n == 1) return 1; // Base case
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

// Recursive function to print numbers from n to 1
void printNumbers(int n) {
    if (n == 0) return; // Base case
    cout << n << " ";
    printNumbers(n - 1); // Recursive case
}

int main() {
    int num;

    // Factorial Example
    cout << "Enter a number to find its factorial: ";
    cin >> num;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;

    // Fibonacci Example
    cout << "Enter the position for Fibonacci series: ";
    cin >> num;
    cout << "Fibonacci(" << num << ") = " << fibonacci(num) << endl;

    // Print Numbers Example
    cout << "Enter a number to print from n to 1 using recursion: ";
    cin >> num;
    cout << "Numbers: ";
    printNumbers(num);
    cout << endl;

    return 0;
}
