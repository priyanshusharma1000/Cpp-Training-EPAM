/*
std::list is a doubly linked list implementation in C++ Standard Template Library (STL). It allows efficient insertions and deletions at both ends and in the middle but has higher memory overhead due to extra pointers.


 Here memory is not contigious

 Key Features of std::list
✅ Implemented as a doubly linked list (each node has pointers to both previous and next nodes).
✅ Efficient insertions and deletions (O(1)) anywhere in the list (unlike std::vector, which requires shifting elements).
✅ Slower random access (O(n)) compared to std::vector (which has O(1) access).
✅ Maintains stable references, pointers, and iterators to elements even after insertions/deletions.

📌 When to Use std::list?
🔹 When frequent insertions/deletions in the middle are required.
🔹 When iterators should remain valid after insertions/deletions.
🔹 When random access is not a priority (as it lacks operator[] like vector).
*/
#include<iostream>
#include<list>
#include<algorithm>
int main(){
    std::list<int>ls{1,3,4,5};
    ls.push_back(6);
    ls.emplace_back(7); // faster than push
    ls.push_front(0);
    ls.emplace_front(-1); //faster than push

    // insert at specific position
    std::list<int>::iterator it = ls.begin();
    std::advance(it,3); // advance do the change in iterator it itself move it to distance 3
    // catch : here we cant do it++  thats why we use advance function
    ls.insert(it,2); 
    
    auto it1 = ls.end();
    ls.insert(it1,8);
 
    auto it2 = ls.begin();

    it2 = std::next(it2,2);
    ls.insert(it2,-10);












    //Accessing Elements (No operator[], Use Iterators)
    std::cout << ls.front()<<std::endl; 
    std::cout << ls.back()<<std::endl;  
    // Using iterators to access all elements
  for (auto it = ls.rbegin(); it != ls.rend(); ++it) {
    std::cout << *it << " "; // 10 20 30
  }
   std::cout<<std::endl;
// Using range-based for loop
    for (int num : ls) {
    std::cout << num << " "; // 10 20 30
    }
    std::cout<<std::endl;
// using for_each function
   for_each(ls.begin(),ls.end(),[](int a){
      std::cout<<a<<" ";
   });
    
    std::cout<<std::endl;

  // Size and Capacity
  std::cout << "Size: " << ls.size()<<std::endl; 
  std::cout << "Is empty: " << ls.empty()<<std::endl;



  //Reversing and Sorting
  ls.reverse();//// Reverse the list
  ls.sort();//// Sort the list (ascending order)
  ls.sort([](int a, int b) { return a > b; });//Sort in descending order using a lambda function


std::list<int> lst1 = {1, 4,6};
std::list<int> lst2 = {2, 3, 5};

// Merge two sorted lists (lst2 becomes empty after merge)
lst1.merge(lst2);  // {1, 2, 3, 4, 5, 6}
std::cout<<std::endl;
for_each(lst1.begin(),lst1.end(),[](int a){
    std::cout<<a<<" ";
 });


//Splicing (Moving Elements Between Lists)
std::list<int> lst3 = {1, 2, 3};
std::list<int> lst4 = {4, 5, 6};

auto itr = lst3.begin();
std::advance(itr, 1); // Move to second element
lst3.splice(itr, lst4);  // Moves all elements of lst2 into lst1 at position 2

// Now lst3 = {1, 4, 5, 6, 2, 3} and lst4 = {}


//we can calculate the lenght of container by this method
std::list<int>l{1,2,3,4};
int dis = distance(l.begin(),l.end());
std::cout<<std::endl<<dis<<std::endl;



//Unique and Removing Elements

std::list<int> lst12 = {1, 2, 2, 3, 3, 4};

// Remove consecutive duplicates
lst12.unique(); // {1, 2, 3, 4}

// Remove elements that satisfy a condition
lst12.remove_if([](int n) { return n % 2 == 0; }); // Removes even numbers


/*
    std::list<int> lp = {1, 100, 2, 3, 10, 1, 11, -1, 12};
 
    auto count1 = lp.remove(1);
    std::cout << count1 << " elements equal to 1 were removed\n";
 
    auto count2 = lp.remove_if([](int n){ return n > 10; });
    std::cout << count2 << " elements greater than 10 were removed\n";
 
    std::cout << "Finally, the list contains: ";
    for (int n : lp)
        std::cout << n << ' ';

    std::cout << '\n';


    This remove and remove_if function is introduced in cpp 20 so it dont run in any prior cpp 
*/

std::list<int> lsg = {7, 5, 16, 8};
 
    // Add an integer to the front of the list
    lsg.push_front(25);
    // Add an integer to the back of the list
    lsg.push_back(13);
 
    // Insert an integer before 16 by searching
    auto it11 = std::find(lsg.begin(), lsg.end(), 16);
    if (it11 != lsg.end())
        lsg.insert(it, 42);
 
    // Print out the list
    std::cout << "lsg = { ";
    for (int n : lsg)
        std::cout << n << ", ";
    std::cout << "};\n";

    
return 0;
}