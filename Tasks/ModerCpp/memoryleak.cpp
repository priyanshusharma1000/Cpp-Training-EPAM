#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
//#include <crtdbg.h>
#include <iostream>

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
};

void createLeak() {
    LeakClass* obj1 = new LeakClass(10);  // Memory leak
    LeakClass* obj2 = new LeakClass(20);  // Another memory leak
}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    createLeak();  // Memory is allocated but never freed
     std::cout << "Program ended. Checking for memory leaks..." << std::endl;
    _CrtDumpMemoryLeaks();  // Detects memory leaks at program exit

    return 0;
}
