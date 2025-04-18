//Producer Consumer OR Bounded Buffer Problem
//
//THE PROBLEM STATEMENT :
//
//Producer will produce and consumer will consume with synchronization of a common buffer.
//
//Until producer thread produces any data consumer thread can't consume.
//
//Threads will use condition_variable to notify each other.
//
//We need mutex if we use condition_variable because CV waits on mutex.
//
//This is one of the example of producer consumer there are many.
//
//PRODUCER thread steps :
//
//lock mutex, if success then go ahead otherwise wait for mutex to get free.
//
//check if buffer is full and if it is full then unlock mutex and sleep, if not then go ahead and produce.
//
//insert item in buffer.
//
//unlock mutex.
//
//notify consumer.
//
//CONSUMER thread steps :
//
//lock mutex, if success then go ahead otherwise wait for mutex to get free.
//
//check if buffer is empty and if it is, then unlock the mutex and sleep, if not than go ahead and consume.
//
//consume item from buffer.
//
//unlock mutex.
//
//notify producer.
//
//IMP:
//Producer and Consumer have to notify each other upon completion of their job.
//




//#include<iostream>
//#include<thread>
//#include<mutex>
//#include<algorithm>
//#include<queue>
//std::mutex m;
//std::condition_variable cd;
//std::deque<int>buffer;
//const unsigned int maxbuffersize = 50;
//
//
//void producer(int val) {
//	while (val) {
//		std::unique_lock<std::mutex>lock(m);
//		cd.wait(lock, []() {return buffer.size() < maxbuffersize;});
//		buffer.push_back(val);
//		std::cout << "Produced: " << val << std::endl;
//		--val;
//		lock.unlock();
//		cd.notify_one();
//	}
//}
//
//void consumer() {
//	while (true) {
//		std::unique_lock<std::mutex>lock(m);
//		cd.wait(lock, []() {return buffer.size() > 0;});
//		int val = buffer.back();
//		buffer.pop_back();
//		std::cout << "consumed: " << val << std::endl;
//		lock.unlock();
//		cd.notify_one();
//		   
//	}
//}
//
//int main() {
//	std::thread t1(producer, 100);
//	std::thread t2(consumer);
//
//	t1.join();
//	t2.join();
//	return 0;
//}

// here in the above code there is a problem of infinte loop lets say producer produce total 100 items and become dead t1.join() is executed successfully
// Now in this code consumer thread is waiting for some notification from producer so that it will be able to consume data but it will never going to happen and as a result t2.join() is not successful and hence we need updated code


//#include<iostream>
//#include<thread>
//#include<queue>
//#include<condition_variable>
//#include<mutex>
//
//std::mutex m;
//std::condition_variable cd;
//
//std::deque<int>buffer;
//unsigned int maxsize = 50;
//bool done = false;// flag to inform consumer that producer is still alive or not
//
//
//void producer(int val) {
//	while (val) {
//		std::unique_lock<std::mutex>lock(m);
//		cd.wait(lock, []() {return buffer.size() < maxsize;});
//		std::cout << "Produced :" << val << std::endl;
//		buffer.push_back(val);
//		--val;
//		lock.unlock();
//		cd.notify_one();
//	}
//
//	std::unique_lock<std::mutex>lock(m);
//	done = true;
//	lock.unlock();
//	cd.notify_one();
//
//}
//void consumer() {
//	while (true) {
//		std::unique_lock<std::mutex>lock(m);
//		cd.wait(lock, []() {return (buffer.size() > 0 || done);});
//		if (buffer.empty() && done)
//			break;
//
//		std::cout << "consumed: " << buffer.back() << std::endl;
//        buffer.pop_back();
//		lock.unlock();
//		cd.notify_one();
//	}
//}
//int main() {
//	std::thread t1(producer, 100);
//	std::thread t2(consumer);
//	t1.join();
//	t2.join();
//	return 0;
//}