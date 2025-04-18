
//Thread t1 locks the mutex and immediately returns due to return 1;.
//
//The unlock is never called, which means m remains permanently locked.
//
//Then, t2 tries to acquire the same mutex but waits forever(deadlock / infinite block).
//
//Since t2.join() never finishes(because t2 is blocked on m.lock()), the program hangs or might abort depending on the system / thread policy.
//#include <iostream>
//#include<mutex>
//#include<thread>
//std::mutex m;
//int fn() {
//    m.lock();
//    return 1;
//    m.unlock();
//}
//int main() {
//    std::thread t1(fn);
//    std::thread t2(fn);
//    t1.join();
//    t2.join();
//    return 0;
//}



//#include<iostream>
//#include<thread>
//#include<mutex>
//
//std::mutex m1;
//std::mutex m2;
//
//void thread1(){
//	m1.lock();
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//	m2.lock();
//	std::cout << "critical section of thread one" << std::endl;
//	m1.unlock();
//	m2.unlock();
//}
//
//void thread2() {
//	m2.lock();
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//	m1.lock();
//	std::cout << "critical section of thread two" << std::endl;
//	m2.unlock();
//	m1.unlock();
//}
//
//int main() {
//	std::thread t1(thread1);
//	std::thread t2(thread2);
//	t1.join();
//	t2.join();
//	return 0;
//}
//


