//c++ array
//Defined in header <array>

/*
//Feature	                           C Array	                          C++ Array(std::array)
//Size Handling	                       sizeof() (manual)	              size() (built - in)
//Bound Checking	                   ❌ No	                          ✅ at() with exception
//Dynamic Allocation	               malloc() / free()	              std::vector(safer)
//Initialization                       {}(partial allowed)                {} (safe, full initialization)
//Passing to Functions	               Passed as pointer	              Pass by reference
//Multi - dimensional                  Support Yes	                      std::vector(dynamic size)
//Operations	                       Manual loops	                      Iterators, range - based loops
*/

#include<iostream>
#include<array>
#include<algorithm>
int main(){
    std::array<int,5>arr{1,2,3,4,5};
    std::cout<<arr.at(4)<<std::endl;
    //std::cout<<arr.at(5)<<std::endl; throw out of range exception
    std::cout<<arr.front()<<std::endl;//same for back
    for_each(arr.rbegin(),arr.rend(),[](const int&a){
     std::cout<<a<<" ";
    });
    std::cout<<std::endl;


}