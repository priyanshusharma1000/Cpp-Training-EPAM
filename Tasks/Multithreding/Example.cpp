//Q.0) What is the use of thread_local ?
//thread_local is a storage specifier in C++ used to declare variables that are local to a thread.Each thread has its own separate instance of the variable.
//Use Case : Useful when multiple threads need to use the same variable name but should not share the same memory.


#include <iostream>
#include <thread>

thread_local int counter = 0;

void func() {
    counter++;
    std::cout << "Thread ID: " << std::this_thread::get_id()
        << " Counter: " << counter << std::endl;
}

int main() {
    std::thread t1(func);
    std::thread t2(func);
    t1.join();
    t2.join();
    return 0;
}



//
//
//-- -
//
//Q.1) What is Singleton class in multithreading ?
//
//A Singleton class ensures that only one instance of the class exists in the entire program, even when accessed by multiple threads.
//
//In multithreading, special care must be taken to prevent multiple threads from creating multiple instances simultaneously.
//
//
//-- -
//
//Q.2) How to create Singleton class with three different methods ?
//
//1. Eager Initialization(Thread - safe by default)
//
//class Singleton {
//private:
//    static Singleton instance;
//    Singleton() {}  // private constructor
//public:
//    static Singleton& getInstance() {
//        return instance;
//    }
//};
//
//Singleton Singleton::instance;
//
//2. Lazy Initialization(Not thread - safe)
//
//class Singleton {
//private:
//    static Singleton* instance;
//    Singleton() {}
//public:
//    static Singleton* getInstance() {
//        if (instance == nullptr) {
//            instance = new Singleton();
//        }
//        return instance;
//    }
//};
//
//Singleton* Singleton::instance = nullptr;
//
//3. Thread - safe Lazy Initialization(Using std::call_once)
//
//#include <mutex>
//
//class Singleton {
//private:
//    static Singleton* instance;
//    static std::once_flag initFlag;
//    Singleton() {}
//public:
//    static Singleton* getInstance() {
//        std::call_once(initFlag, []() {
//            instance = new Singleton();
//            });
//        return instance;
//    }
//};
//
//Singleton* Singleton::instance = nullptr;
//std::once_flag Singleton::initFlag;
//
//
//---
//
//Q.3) How to detect and eliminate deadlock from the code ?
//
//Deadlock occurs when two or more threads wait indefinitely for each other to release locks.
//
//Detection(Manual or Tools) :
//
//    Manually check the lock acquisition order.
//
//    Use tools like Valgrind, Helgrind, Intel Inspector, or Visual Studio Concurrency Visualizer.
//
//
//    Example of deadlock :
//
//std::mutex m1, m2;
//
//void task1() {
//    std::lock_guard<std::mutex> lock1(m1);
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    std::lock_guard<std::mutex> lock2(m2); // Waits for m2
//}
//
//void task2() {
//    std::lock_guard<std::mutex> lock2(m2);
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    std::lock_guard<std::mutex> lock1(m1); // Waits for m1
//}
//
//Solution(Avoidance using std::lock) :
//
//    void task() {
//    std::lock(m1, m2);
//    std::lock_guard<std::mutex> lock1(m1, std::adopt_lock);
//    std::lock_guard<std::mutex> lock2(m2, std::adopt_lock);
//}
//
//Or define a consistent lock order across threads.