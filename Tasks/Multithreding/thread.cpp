#include<iostream>
#include<thread>
// There are 5 different types we can create thread in cpp 11 using callable object
// NOTE:
// if we create multiple thread at same time it does not guarntee which will start first


//// 1 Function pointer 
//// this is very basic form of thread creation

//void fun(int x) {
//	while (x-- > 0) {
//		std::cout << x << std::endl;
//	}
//}
//int main() {
//	std::thread t(fun, 10);
//	t.join();
//	return 0;
//}

// 2 lambda expression
//auto fun = [](int x) {
//	while (x-- > 0) {
//		std::cout << x << std::endl;
//	}
//};
//
//int main() {
//	std::thread t(fun, 10);
//	t.join();
//	return 0;
//}


// we can directly inject lambda at thread creation time
//int main() {
//	std::thread t([](int x) {
//		while (x-- > 0) {
//			std::cout << x << std::endl;
//		}
//		}, 10);
//	t.join();
//	return 0;
//}


//3 function object (functor)

//class base {
//public:
//	void operator()(int x) {
//		while (x-- > 0) {
//			std::cout << x << std::endl;
//		}
//	}
//};
//int main() {
//	std::thread t(base(), 10);
//	t.join();
//	return 0;
//}



// 4 Non-static member function 

//class base {
//public:
//	void run(int x) {
//		while (x-- > 0) {
//			std::cout << x << std::endl;
//		}
//	}
//};
//int main() {
//	base b;
//	std::thread t(&base::run, b, 10);
//	t.join();
//	return 0;
//}



// 5 static member function
//class base {
//public:
//	static void run(int x) {
//		while (x-- > 0) {
//			std::cout << x << std::endl;
//		}
//	}
//};
//int main() {
//	std::thread t(&base::run, 10);
//	t.join();
//	return 0;
//}

