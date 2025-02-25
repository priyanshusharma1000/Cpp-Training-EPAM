// Name mangling
/*C++ supports function overloading, i.e., there can be more than one function with the same name but
 different parameters. How does the C++ compiler distinguish between different functions when it generates 
 object code – it changes names by adding information about arguments. This technique of adding additional 
 information to function names is called Name Mangling. C++ standard doesn’t specify any particular technique
  for name mangling, so different compilers may append different information to function names. */

  #include<iostream>
  #include<stdio.h>
  using namespace std;
   
  extern "C"{  // by writing extern C we are telling to compiler that you should take necessary action not to mangle the printf 
               // function of c library
  int printf(char* ch){
    
  };
}
  int main(){
    printf("hi");
    return 0;
  }