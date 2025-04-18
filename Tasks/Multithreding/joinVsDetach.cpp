//Situation You Described :
//You created a thread in main()
//
//You did t.detach()
//
//Now the thread is running independently in background
//
//Then main() finishes before the thread completes



//What Happens in This Case ?
//✅ Answer :
//The detached thread gets killed if the main thread exits and the process ends before the detached thread finishes execution.



//Why ?
//Because :
//
//	The entire process ends once main() completes.
//
//	When a process ends, all of its threads are destroyed, even if they are still running.
//
//	A detached thread has no owner, so the system just cleans it up silently — like a background worker that’s abandoned mid - task.





// here in the below case the same happen 
//#include<iostream>
//#include<thread>
//
//void backgroundtask() {
//	std::cout << "Deteched thread started" << std::endl;
//	std::this_thread::sleep_for(std::chrono::seconds(5));
//	std::cout << "Detached thread finished" << std::endl;
//}
//
//int main() {
//	std::thread t(backgroundtask);
//	t.detach();
//	std::cout << "Main thread exiting immediately" << std::endl;
//}
//Detached thread started.
//Main thread exiting immediately.
//❌ "Detached thread finished." might not print at all — the thread gets killed as the process dies.







// FOLLOW UP 
// HOW TO MAKE SURE THAT THE DETACH THREAD FINISHES

// 1 you can force main to wait artificially (if needed)
//std::this_thread::sleep_for(std::chrono::seconds(6)); // Give enough time for detached thread to finish for main
// 2. it is better than previous approach 
//Use a join() when result is important
//Use a thread pool or task queue in real systems where background tasks need lifecycle management



//use join when                                                             use detach when
//You need results from thread or execution must complete                   Task can run in background without caring for result
//You want synchronized, predictable execution                              Thread is doing independent, non - critical work
//Shared resources are involved                                             No shared data or it’s read - only
//Example : Math calc, DB ops, file processing                              Example : Logging, Monitoring, Background cleanup