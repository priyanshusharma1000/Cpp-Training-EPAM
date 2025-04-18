// TOPIC : std::async(automatic thread creation)
// it is capable of returning the result unlike promise and future combination
// deffered locking system -> create a new thread and that will run when we do future object.get()
// async locking system ->does not create new thread but perform operation in main thread only


//NOTES
//1.It runs a function asynchronously (potentially in a new thread) and returns a std::future that will hold the result.
//2.There are three launch policies for creating task  :
//   a. std::launch::async
//   b. std::launch::deffered
//   c. std::launch::async | std::launch::deffered 


// HOW IT WORKSI have a college practical scheduled and need to take leave for it. Piyush has already received the official mail from the college regarding this and has advised me to update the same on the vacation portal. Kindly approve the leave.
//1.It automatically creates a thread(or picks from internal thread pool) and a promise object for us.
//2. Then passes the std::promise object to thread function and returns the associated std::future object.
//3. When our passes argument function exists then its value will be sent in this promise object,
//   so eventually return value will be available in std::future object

//SIDE NOTES:
//1 we can send functor and lambda function as callback to std::async,it will work the same.

//#include<iostream>
//#include<thread>
//#include<future>
//#include<algorithm>
//#include<chrono>
//typedef long  long int ull;
//
//ull findOdd(ull start, ull end) {
//	ull oddsum = 0;
//	std::cout << "Thread Id:" << std::this_thread::get_id() << std::endl;
//	for (ull i = start;i <= end;i++) {
//		if (i & 1) {
//			oddsum += i;
//		}
//	}
//	return oddsum;
//}
//
//int main() {
//	ull start = 0, end = 19000;
//	std::cout << "Thread Id:" << std::this_thread::get_id() << std::endl;
//	std::future<ull>Oddsum = std::async(std::launch::deferred, findOdd, start, end);
//	std::cout << "Waiting for the result" << std::endl;
//	std::cout << "Oddsum :" << Oddsum.get() << std::endl; // function will execute at this line and we are waiting here(blocking state until we cant get value from function it is in same thread no new thread is created)
//	std::cout << std::endl;
//	return 0;
//}



//#include<iostream>
//#include<thread>
//#include<future>
//#include<algorithm>
//#include<chrono>
//typedef long  long int ull;
//
//ull findOdd(ull start, ull end) {
//	ull oddsum = 0;
//	std::cout << "Thread Id:" << std::this_thread::get_id() << std::endl;
//	for (ull i = start;i <= end;i++) {
//		if (i & 1) {
//			oddsum += i;
//		}
//	}
//	return oddsum;
//}
//
//int main() {
//	ull start = 0, end = 19000;
//	std::cout << "Thread Id:" << std::this_thread::get_id() << std::endl;
//	std::future<ull>Oddsum = std::async(std::launch::async, findOdd, start, end); // here in async launching the new thread will be created which is executing the function so we dont have to wait for the result at point oddsum.get() to get the value if it is already calculate
//	std::cout << "Waiting for the result" << std::endl;
//	std::cout << "Oddsum :" << Oddsum.get() << std::endl; 
//	return 0;
//}




