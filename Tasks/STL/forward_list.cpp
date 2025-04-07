/*
std::forward_list is a container that supports fast insertion and removal of elements from anywhere in the container. Fast random access is not supported. It is implemented as a singly-linked list. Compared to std::list this container provides more space efficient storage when bidirectional iteration is not needed.


 only front operation is allowed



*/
#include<iostream>
#include<forward_list>
int main(){
    int main()
{
    std::forward_list<int> list1 = {5, 9, 1, 3, 3};
    std::forward_list<int> list2 = {8, 7, 2, 3, 4, 4};
 
    list1.sort();
    list2.sort();
    std::cout << "list1: " << list1 << '\n';
    std::cout << "list2: " << list2 << '\n';
 
    list1.merge(list2);
    std::cout << "merged:" << list1 << '\n';
}
}