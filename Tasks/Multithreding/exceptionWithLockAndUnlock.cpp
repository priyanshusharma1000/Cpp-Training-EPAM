//Caution: Manual lock() and unlock() Can Be Dangerous
//What if an exception occurs between lock() and unlock() ?
//→ The mutex might never be released — leading to deadlocks!

//#include<iostream>
//#include<thread>
//#include<mutex>
//
//std::mutex m;
//
//void unsafetask() {
//	m.lock();
//	std::cout << "Thread acquired lock" << std::endl;
//	throw std::runtime_error("something went wrong");
//	m.unlock(); // this line never execute
//}
//
//void anothertask() {
//	std::this_thread::sleep_for(std::chrono::milliseconds(100));
//	std::cout << "Another thread trying to acquire the lock" << std::endl;
//	m.lock();// will block forever because the lock is never relased
//	std::cout << "Another thread acquired lock" << std::endl;
//	m.unlock();
//}

//int main() {
//	try {
//		std::thread t1(unsafetask);
//		std::thread t2(anothertask);
//
//		t1.join();
//		t2.join();
//	}
//	catch (const std::exception& e) {
//		std::cerr << "Exception caught in main :" << e.what() << std::endl;
//	}
//
//
//	std::cout << "finished" << std::endl;
//	return 0;
//}
// THAT IS WHY USE LOCKGUARD WHICH IS RAII CONCEPT SIMILAR TO WHAT WE USE SMART POINTER 