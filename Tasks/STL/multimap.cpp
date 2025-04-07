/*
This is an important STL associative container used when multiple values can be associated with the same key, unlike std::map, where keys are unique

What is std::multimap?
A sorted associative container that stores key-value pairs, allowing duplicate keys.

Internally implemented as a balanced binary search tree (usually Red-Black Tree).

Automatically sorts elements by the key using operator< by default.

#include <map>

std::multimap<KeyType, ValueType> name;

Feature	                             Description
Duplicate keys                       allowed	✔️
Automatically sorted	             ✔️ by key
Key-Value access	                  ✔️
Underlying structure	              Red-Black Tree

Tree
📦 Use Cases
When one key can have multiple associated values.

Example: Student marks (roll number as key, subject marks as values), bank transactions (account no. → list of transactions), etc.





 Common Functions of std::multimap
Function	    Description
insert()	   Adds key-value pair (allows duplicates)
emplace()	   Constructs and inserts element in-place
find(key)	  Returns iterator to first matching key
count(key)	  Returns number of elements with given key
equal_range(key)  Returns range (pair of iterators) for a given key
erase(key or iterator)	Removes elements
clear()	Removes all elements
size()	Number of elements
empty()	Checks if container is empty
begin(), end()	Iterators to traverse
lower_bound(key)	First element not less than key
upper_bound(key)	First element greater than key
*/
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> students;

    students.insert({101, "Rahul"});
    students.insert({102, "Priya"});
    students.insert({101, "Amit"});
    students.insert({103, "Sneha"});

    // Display all students
    for (auto& [roll, name] : students) {
        std::cout << roll << " -> " << name << "\n";
    }

    // Count students with roll number 101
    std::cout << "Count of roll 101: " << students.count(101) << "\n";

    // Equal range demo
    auto range = students.equal_range(101);
    std::cout << "Students with roll 101:\n";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << "\n";
    }

    return 0;
}
/*
Things to Note
multimap does not provide operator[] for access/modification like map because there can be multiple values per key.

All elements with the same key are stored in insertion order (relative to each other).

Internally sorted → efficient lookup with logarithmic time complexity.
*/
/*
Think of a multimap like a dictionary of synonyms:
Word: "happy"
→ Meaning1: "joyful"
→ Meaning2: "cheerful"
→ Meaning3: "content"
Here, the word is the key, and meanings are values. This can't be done with a map since it allows only one value per key.
*/
/*
✅ Summary
Property	     std::map	              std::multimap
Key uniqueness	Unique keys only	 Duplicate keys allowed
[] access	    Yes	                       No
Use case	1-to-1 mapping	         1-to-many mapping
*/
/*
#include<iostream>
#include<map>
int main(){
    std::multimap<int,std::string>mp;
    mp.emplace(103,"sparsh");
    mp.insert(std::make_pair(101,"priyanshu"));
    mp.emplace(102,"sumit");
    mp.insert({101,"sharma"});
    mp.emplace(102,"hada");
   
    
    for(auto& [roll,name] : mp){
        std::cout<<roll<<"-->"<<name<<std::endl;
    }
    std::cout<<std::endl;
    for(auto i:mp){
        std::cout<<i.first<<"-->"<<i.second<<std::endl;
    }
    
    std::cout<<std::endl;
    if(mp.find(101)!=mp.end()){
        auto it = mp.find(101);
        std::cout<<it->second<<std::endl;
    }
    
    
    std::cout<<"number of entries correspond to roll no 101 is :"<<mp.count(101)<<std::endl;
    
    auto range = mp.equal_range(100);
    for(auto it = range.first;it!=range.second;++it){
        std::cout<<it->first<<"-->"<<it->second<<std::endl;
    }
    
}
*/


//IMPORTANT
//question : how to remove all values for specific key
// answer
/*Since std::multimap allows multiple values for the same key, you can remove all values using equal_range() + erase().
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> records = {
        {1, "Amit"}, {2, "Riya"}, {1, "Raj"}, {3, "Sneha"}, {1, "Neha"}
    };

    std::cout << "Before deletion:\n";
    for (auto& [id, name] : records) {
        std::cout << id << " -> " << name << "\n";
    }

    // Remove all entries with key = 1
    auto range = records.equal_range(1);
    records.erase(range.first, range.second);

    std::cout << "\nAfter deletion of key 1:\n";
    for (auto& [id, name] : records) {
        std::cout << id << " -> " << name << "\n";
    }

    return 0;
}
*/



/*
Grouping Data Using std::multimap — Real-Life Project-Like Example

🎯 Scenario:
Group students by their departments.
#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<std::string, std::string> departmentStudents;

    // Inserting department -> student
    departmentStudents.insert({"CSE", "Amit"});
    departmentStudents.insert({"ECE", "Neha"});
    departmentStudents.insert({"CSE", "Priya"});
    departmentStudents.insert({"ME", "Rahul"});
    departmentStudents.insert({"CSE", "Sohan"});
    departmentStudents.insert({"ECE", "Sneha"});

    // Grouped Output
    std::cout << "Grouped students by departments:\n";

    std::string last_dept = "";
    for (auto& [dept, student] : departmentStudents) {
        if (dept != last_dept) {
            std::cout << "\nDepartment: " << dept << "\n";
            last_dept = dept;
        }
        std::cout << " - " << student << "\n";
    }

    return 0;
}
Grouped students by departments:

Department: CSE
 - Amit
 - Priya
 - Sohan

Department: ECE
 - Neha
 - Sneha

Department: ME
 - Rahul

*/
/*
Bonus Tip: When to Prefer multimap over unordered_multimap?
Use multimap when:

Order matters

You need range-based lookups

You prefer logarithmic time operations (due to tree structure)

Use unordered_multimap when:

Order does not matter

You want average constant time operations (uses hashing)








will have project using multimap
*/



