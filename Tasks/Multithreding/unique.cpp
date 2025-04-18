//In this we will learn how to use unique_lock In C++ programming language.
//Few important points to remember about the unique_lock is as follows :
//1. The class unique_lock is a mutex ownership wrapper.
//2. It Allows :
//a.Can Have Different Locking Strategies
//b.time - constrained attempts at locking(try_lock_for, try_lock_until)
//c.recursive locking
//d.transfer of lock ownership(move not copy)
//e.condition variables. (See this in coming videos)
//
//Locking Strategies
//TYPE           EFFECTS(S)
//1. defer_lock  do not acquire ownership of the mutex.
//2. try_to_lock  try to acquire ownership of the mutex without blocking.
//3. adopt_lock  assume the calling thread already has ownership of the mutex.





//What it is :
//A more flexible and feature - rich wrapper than lock_guard.
//
//Supports delayed locking, manual unlock / lock, lock ownership transfer, and more.







//Feature	Supported :
//Deferred Locking	?
//Try - lock(non - blocking)	?
//Manual lock / unlock	?
//Transfer ownership	?
//Works with std::condition_variable	?




////std::unique_lock Locking Strategies
//std::mutex m;
//
//// 1. Immediate locking (like lock_guard)
//std::unique_lock<std::mutex> lock1(m);
//
//// 2. Defer locking
//std::unique_lock<std::mutex> lock2(m, std::defer_lock); // No lock yet
//lock2.lock();  // Now explicitly lock it
//
//// 3. Try-lock
//std::unique_lock<std::mutex> lock3(m, std::try_to_lock);
//if (lock3.owns_lock()) {
//    // acquired successfully
//}
//else {
//    // couldn't acquire lock
//}
//
//// 4. Adopt already locked mutex
//m.lock();
//std::unique_lock<std::mutex> lock4(m, std::adopt_lock); // assumes you already locked it




//?? Summary Table
//
//
//Feature	std::              lock_guard	                                                    std::unique_lock
//Immediate Lock	              ?																?
//Delayed Lock				  ?																?(std::defer_lock)
//Manual Unlock				  ?																?(lock.unlock())
//Try - Lock					  ?																?(std::try_to_lock)
//Ownership Transfer			  ?																?(movable)
//Works with cond.variable	  ?																?
//Performance(lightweight)	  ?(faster)														?(slightly heavier)
//Exception Safety			  ?																?








//When to Use What?
//Situation	                                                                                Use
//Simple scope - based lock, no manual control needed	                                       lock_guard
//Need to manually unlock / re - lock inside a function	                                   unique_lock
//Using std::condition_variable	                                                           unique_lock
//Try - lock or deferred lock strategy needed	                                               unique_lock
//Tight performance - critical sections	                                                   lock_guard



// mini expample 
//std::mutex m;
//void fun() {
//    std::unique_lock<std::mutex> lock(m, std::defer_lock); // defer locking
//    if (/* some condition */) {
//        lock.lock();   // lock now if needed
//    }
//}


// pro tip
//Prefer lock_guard for simplicity.
//Use unique_lock only when you really need the advanced flexibility.

