//Topic Name: streams in cpp
//This file is created by : Priyanshu sharma
#include <iostream>
#include<string>
#include <fstream>  // Required for file handling
using namespace std;


/*
<fstream> is a C++ file handling library that provides classes to perform file input and output operations.

Classes in <fstream>:

ofstream (Output File Stream) → Used for writing to files.

ifstream (Input File Stream) → Used for reading from files.

fstream (File Stream) → Can perform both read and write 

operations.
Objects of These Classes:

outFile is an object of ofstream, used to write to a file.
inFile is an object of ifstream, used to read from a file.
*/
int main() {
    // Writing to a file
    ofstream outFile("example.txt");  // Create and open a file
    outFile << "Hello, this is a file stream example in C++!\n";
    outFile.close();  // Close the file

    // Reading from a file
    ifstream inFile("example.txt");
    string content;
    
    cout << "Reading from file: ";
    while (getline(inFile, content)) {  // Read line by line
        cout << content << endl;
    }
    inFile.close();  // Close the file

    return 0;
}
// it will create the file in the same directory in which your .cpp file is located after compilation