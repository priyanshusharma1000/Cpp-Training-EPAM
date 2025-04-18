/*
1. What do you understand by thread and give one example in C++?

ANSWER
0. In every application there is a default thread which is main(), in side this we create other threads.
1. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads.
   For example:
   (a) The browser has multiple tabs that can be different threads.
   (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
   (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

WAYS TO CREATE THREADS IN C++11
1. Function Pointers
2. Lambda Functions
3. Functors
4. Member Functions
5. Static Member functions
*/


#include<iostream>
#include<thread>
#include<chrono> // for clock
#include<algorithm>
typedef long long int ull;

void findEven(ull start, ull end, ull* Evensum) {
	for (ull i = start;i <= end;i++) {
		if (!(i & 1)) {
			*(Evensum) += i;
		}
	}
}

void findOdd(ull start, ull end, ull* Oddsum) {
	for (ull i = start;i <= end;i++) {
		if ((i & 1)) {
			*(Oddsum) += i;
		}
	}
}

//int main() {
//	ull start = 0,end = 1900000000;
//	ull Oddsum = 0, Evensum = 0;
//
//
//	auto startTime = std::chrono::high_resolution_clock::now();
//	std::thread t1(findEven, start, end, &(Evensum));
//	std::thread t2(findOdd, start, end, &(Oddsum));
//
//
//
//	
//	//findEven(start, end, &(Evensum));
//	//findOdd(start, end, &(Oddsum));
//	auto endTime = std::chrono::high_resolution_clock::now();
//
//	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
//
//
//
//	std::cout << "sec :" << duration.count() / 1000000 << std::endl;
//	return 0;
//}