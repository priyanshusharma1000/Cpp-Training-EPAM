//This file is created by Priyanshu sharma!
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 3; // 5 -> 0101, 3 -> 0011 (in binary)
    
    cout << "a = " << a << ", b = " << b << endl;

    // Bitwise AND
    cout << "a & b = " << (a & b) << endl;  // 0101 & 0011 = 0001 (1)

    // Bitwise OR
    cout << "a | b = " << (a | b) << endl;  // 0101 | 0011 = 0111 (7)

    // Bitwise XOR
    cout << "a ^ b = " << (a ^ b) << endl;  // 0101 ^ 0011 = 0110 (6)

    // Bitwise NOT
    cout << "~a = " << (~a) << endl; // ~(0000 0101) = 1111 1010 (2's complement: -6)

    // Left Shift
    cout << "a << 1 = " << (a << 1) << endl;  // 0101 << 1 = 1010 (10)

    // Right Shift
    cout << "a >> 1 = " << (a >> 1) << endl;  // 0101 >> 1 = 0010 (2)

    // Operator precedence demonstration
    int result = a | b & a ^ b;
    // According to precedence:
    // 1. Bitwise AND (&) -> (b & a) => (3 & 5) => 0001 (1)
    // 2. Bitwise XOR (^) -> (1 ^ b) => (1 ^ 3) => 0010 (2)
    // 3. Bitwise OR (|) -> (a | 2) => (5 | 2) => 0111 (7)

    cout << "Operator precedence result (a | b & a ^ b) = " << result << endl;

    return 0;
}
