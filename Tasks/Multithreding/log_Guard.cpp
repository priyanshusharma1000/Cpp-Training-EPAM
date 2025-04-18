//In this we will learn about lock_guard in threading in C++ programming language.
// syntax  - > std::lock_guard<mutex>lock(m1))
//Few points to remember about the lock_guard is as follows :
//0. It is very light weight wrapper for owning mutex on scoped basis.
//1. It acquires mutex lock the moment you create the object of lock_guard.
//2. It automatically removes the lock while goes out of scope.
//3. You can not explicitly unlock the lock_guard.
//4. You can not copy lock_guard.


//#include<iostream>
//#include<thread>
//#include<mutex>
//
//std::mutex m1;
//int buffer = 0;
//
//void task(const char* threadno, int loopfor) {
//	std::lock_guard<std::mutex>lock(m1);
//	for (int i = 0;i < loopfor;i++) {
//		std::cout << threadno   << buffer++ << std::endl;
//	}
//}
//// manual locking and unlocking is replaced by lock_guard as it is scope based and it is a RAII concept
//
//int main() {
//	std::thread t1(task, "T0", 10);
//	std::thread t2(task, "T1", 10);
//	t1.join();
//	t2.join();
//	std::cout << "Buffer is :" << buffer << std::endl;
//	return 0;
//}
