// topic : exception handling + function pointer 
// this file is cretaed by priyanshu sharma 
#include <iostream>
using namespace std;

void display(int a) {
    cout << "Result: " << a << endl;
}

int calculator(int a, int b, void (*dptr)(int)) {
    cout << "Press 1 for Addition\n";
    cout << "Press 2 for Subtraction\n";
    cout << "Press 3 for Multiplication\n";
    cout << "Press 4 for Division\n";

    try {
        int i;
        cout << "Enter your choice: ";
        if (!(cin >> i)) {
            throw runtime_error("Invalid input! Please enter a number.");
        }

        int res;
        switch (i) {
        case 1:
            res = a + b;
            break;
        case 2:
            res = a - b;
            break;
        case 3:
            res = a * b;
            break;
        case 4:
            if (b == 0)
                throw runtime_error("Error: Division by zero is not allowed.");
            res = a / b;
            break;
        default:
            throw runtime_error("Invalid choice! Please pick a valid operation (1-4).");
        }

        dptr(res);
    }
    catch (const exception &e) {
        cout << "Exception in calculator: " << e.what() << endl;
        return -1; // Indicating error occurred
    }
    return 0;
}

int main() {
    try {
        int a, b;
        cout << "Enter two numbers a and b: ";
        
        if (!(cin >> a >> b)) {
            throw runtime_error("Invalid input! Please enter numbers.");
        }

        calculator(a, b, display);
    }
    catch (const exception &e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

    return 0;
}
