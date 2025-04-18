//In this we will learn about how std::promise and std::future and how they work together to synchronise threads.
//Basically std::promise is sent to the called thread and once the value is ready we set that value in promise object, now at calling thread side we get that value using std::future object which was created using std::promise object before sending it to the called thread.And this is how we receive value from one thread to another in synchronisation.


//TOPIC : std::future and std::threading 
//
//1. std::Promise
//a. used to set values and exceptions
//
//2. std::future
//a. used to get value from promise
//b. ask promise if the value is available
//c. wait for the promise


//#include<iostream>
//#include<thread>
//#include<chrono>
//#include<algorithm>
//#include<future>
//typedef long long int ull;
//
//void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end) {
//	ull Oddsum = 0;
//	for (ull i = start;i <= end;++i) {
//		if (i & 1)
//			Oddsum += i;
//	}
//	OddSumPromise.set_value(Oddsum);
//}
//
//int main() {
//	ull start = 0, end = 1900000000;
//
//	std::promise<ull>OddSum;
//
//	std::future<ull>OddFuture = OddSum.get_future();
//
//	std::cout << "Thread created!!" << std::endl;
//	std::thread t1(findOdd, std::move(OddSum), start, end);
//
//	std::cout << "Waiting for the reult!!" << std::endl;
//	std::cout << "OddSum" << OddFuture.get() << std::endl;
//	std::cout << "completed" << std::endl;
//	t1.join();
//	return 0;
//}
//
//





//What is std::future and std::promise ?
//These two are part of the <future> header in C++, and they are used for thread synchronization and communication between threads.
//
//
//
//🔸 Analogy
//Imagine two friends :
//
//🧑‍💻 One will cook dinner(worker thread).
//
//🍽️ The other is waiting to eat(main thread).
//
//But the eater doesn't know when dinner will be ready.
//
//So the cook promises, “I'll tell you when it’s done.” That’s std::promise.
//
//And the eater holds the std::future, like a notification slip.When dinner is ready, the promise sets the result, and the future gets it.
//
//
//#include <iostream>
//#include <thread>
//#include <future>
//
//void doWork(std::promise<int> p) {
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//    p.set_value(42); // Set result
//}
//
//int main() {
//    std::promise<int> p;
//    std::future<int> f = p.get_future(); // Get future from promise
//
//    std::thread t(doWork, std::move(p));
//
//    std::cout << "Waiting for result...\n";
//    int result = f.get(); // Blocks until set_value() is called
//    std::cout << "Result is: " << result << "\n";
//
//    t.join();
//    return 0;
//}
//
//
//Key Points :
//
//std::promise<T> is used to set a value(or an exception).
//
//std::future<T> is used to get that value, possibly waiting until it's ready.
//
//f.get() blocks until p.set_value(...) is called.
//
//
//
//🔸 Why Use Them ?
//They help :
//
//Communicate between threads(pass result from one to another).
//
//Synchronize threads(wait until a task is done).
//
//Handle exceptions across threads.
//
//Get return values from a thread function like we do in normal functions.


//#include<iostream>
//#include<thread>
//#include<future>
//void fun(std::promise<int>&& p, int s, int e)
//{
//	int oddsum = 0;
//	for (int i = 0;i <= e;i++) {
//		if(i&1)
//		oddsum += i;
//	}
//	p.set_value(oddsum);
//}
//int main() {
//	// start to end odd number sum
//	int s = 0, e = 1000;
//	std::promise<int>p;
//	std::future<int> f = p.get_future();
//	std::thread t1(fun,std::move(p), s, e);
//	std::cout << f.get() << std::endl; // blocked until p.setvalue() is not executed in function fun
//	return 0;
//}