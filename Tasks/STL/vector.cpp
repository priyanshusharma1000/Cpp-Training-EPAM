#include<iostream>
#include<vector>
#include<algorithm>// sort,for_each is definded in this 
#include <numeric> //accumulate

// here contigous memory location 
int main(){
    std::vector<int>nums;
    std::cout<<"size :"<<nums.size()<<std::endl;
    std::cout<<"capacity :"<<nums.capacity()<<std::endl;
    
    nums.push_back(2);
    std::cout<<"size :"<<nums.size()<<std::endl;
    std::cout<<"capacity :"<<nums.capacity()<<std::endl;

    nums.push_back(3);
    std::cout<<"size :"<<nums.size()<<std::endl;
    std::cout<<"capacity :"<<nums.capacity()<<std::endl;

    nums.emplace_back(4);
    std::cout<<"size :"<<nums.size()<<std::endl;
    std::cout<<"capacity :"<<nums.capacity()<<std::endl;


    nums.shrink_to_fit();
    std::cout<<"size :"<<nums.size()<<std::endl;
    std::cout<<"capacity :"<<nums.capacity()<<std::endl;



    /*
      The storage of the vector is handled automatically, being expanded as needed. Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth. This way a vector does not need to reallocate each time an element is inserted, but only when the additional memory is exhausted. The total amount of allocated memory can be queried using capacity() function. Extra memory can be returned to the system via a call to shrink_to_fit()[1].
    */


    nums.emplace_back(7);
    std::cout<<"size :"<<nums.size()<<std::endl;
    std::cout<<"capacity :"<<nums.capacity()<<std::endl;



    for(std::vector<int>::iterator it=nums.begin();it!=nums.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    // also print using range based loop
    for(auto i:nums){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    

  
   // erase function take iterator of the element that we want to remove 
   /*if single iterator as argument ->it remove the element that the iterator is pointing to
      
   iterator erase( iterator pos );
   Removes the element at pos
   */
  

  /*
     if double iterator as argument -> it remove the element between those iterators
      
     iterator erase( iterator first, iterator last );
      
     Removes the elements in the range [first, last).


     more info on cppreference website
  
  */ 




  /*
     Q) REMOVE ALL EVEN ELEMENT FROM VECTOR 
     sol) Do using erase function
  */

   std::vector<int>c{3,4,6,78,8,9,3,2,4,2,5,7,0,1,2,5,7};
   for(std::vector<int>::iterator it =c.begin();it!=c.end();)
   {
      if(*it%2==0)
      it = c.erase(it); //  now it is pointing to the next element to the erased element
      else
      it++;
   }

   // vector after deleting all even numbers

   for(std::vector<int>::iterator it = c.begin();it!=c.end();it++){
    std::cout<<*it<<" ";
   }

 // some useful operation in vector

  std::vector<int>vec{3,4,7,8,9};
  std::cout<<std::endl;
  std::cout<<"front element :"<<vec.front()<<std::endl;
  std::cout<<"back element :"<<vec.back()<<std::endl;
  // rather than using [] always use at function because it will throw out_of_range exception ulike []
  //std::cout<<"element at index 5 is::"<<vec.at(5)<<std::endl;//terminate called after throwing an instance of 'std::out_of_range'

  // but in case of [index] it will no throw any exception if we try to access the index which is not present in array
  std::cout<<"element at index 5 is :"<<vec[5]<<std::endl; // random values


  int sum = accumulate(vec.begin(),vec.end(),1);
  std::cout<<"sum is :"<<sum<<std::endl;


  int productvalue = accumulate(vec.begin(),vec.end(),1,std::multiplies<int>());
  std::cout<<"product value is :"<<productvalue<<std::endl;



  // difference between begin() and cbegin() 
  // cbegin stands for constant begin() and it does not allow to change the value where it is used
  for_each(vec.begin(),vec.end(),[](int& a){
    a = a*2;
    std::cout<<a<<" ";
  });
  std::cout<<std::endl;
  for_each(vec.cbegin(),vec.cend(),[](const int& a){
   // a = a*2; constant iterator does not allow the modification of the values
    std::cout<<a<<" ";
  });
  

  // always begin() is a iterator which is derefrencable and end() is not derefrencable 
  // how to check whether a container is empty or not 
  // if begin() == end()

    return 0;
}