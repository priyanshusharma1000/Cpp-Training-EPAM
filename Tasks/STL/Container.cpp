/*
Types of Containers in C++ STL
Containers are data structures that store collections of objects. STL provides different types of containers classified into:

(A) Sequence Containers
These store elements in a linear fashion.

vector - Dynamic array with fast random access.

list - Doubly linked list, allowing fast insertions/deletions anywhere.

forward_list - Singly linked list, more memory-efficient than list.

deque (Double-ended queue) - Fast insertions and deletions at both ends.

array (std::array) - Fixed-size array with stack memory allocation.

(B) Associative Containers
These store elements in a sorted manner and allow fast retrieval.

set - Stores unique elements in sorted order.

multiset - Allows duplicate elements, sorted.

map - Key-value pair, sorted by key, unique keys only.

multimap - Key-value pair, sorted by key, allows duplicate keys.

(C) Unordered Associative Containers
These store elements in unordered (hashed) form for faster access.

unordered_set - Stores unique elements without sorting.

unordered_multiset - Allows duplicates, no sorting.

unordered_map - Key-value pair, unique keys, no sorting.

unordered_multimap - Key-value pair, allows duplicate keys.

(D) Container Adapters
These are wrappers over existing containers.

stack - LIFO (Last In First Out) based on deque by default.

queue - FIFO (First In First Out) based on deque by default.

priority_queue - Max-heap or min-heap by default.


*/
