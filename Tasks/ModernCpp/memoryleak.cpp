#define _CRTDBG_MAP_ALLOC

#include <cstdlib>

#include <crtdbg.h>

#include <iostream>

#include <fcntl.h>

#include <io.h>

class LeakClass {

private:

    int* arr;

    int size;

public:

    LeakClass(int s) {

        size = s;

        arr = new int[size];  // Memory allocated but never freed

        for (int i = 0; i < size; i++) {

            arr[i] = i + 1;

        }

        std::cout << "Memory allocated for " << size << " integers." << std::endl;

    }

    ~LeakClass() {

        delete[] arr;

        std::cout << "destructor invoked" << std::endl;

    }

};

void createLeak() {

    LeakClass* obj1 = new LeakClass(10);  // Memory leak

    LeakClass* obj2 = new LeakClass(20);  // Another memory leak

    delete obj1;
    delete obj2;

}

int main() {

    // Set debugging flags

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    // Redirect memory leak output to the console

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);

    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);  // Redirects to console

    createLeak();  // Memory is allocated but never freed

    std::cout << "Program ended. Checking for memory leaks..." << std::endl;

    _CrtDumpMemoryLeaks();  // 🚀 Now prints leaks to the console

    return 0;

}

