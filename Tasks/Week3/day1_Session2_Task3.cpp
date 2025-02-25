// constructor intialization list with user defined data type as class data member
#include<iostream>
using namespace std;

class tempClass{
    public:
    tempClass(){
        cout<<"Inside temp class constructor"<<endl;
    }
};

class myBaseClass{
  public:
  int x;
  int x1;
  tempClass tempClassobj;
  myBaseClass(int x=0){
    this->x = x;
    cout<<"Inside Base const"<<endl;
  }

  /*
    myBaseClass (tempClass obj){
     tempClassobj = obj;
  }
  */
  

  /*When you pass `tempObj` of `tempClass` to the constructor of `myBaseClass` which uses assignment in the body (`myBaseClass(tempClass obj) { tempClassobj = obj; }`), the following happens:

1. `tempClassobj` is first default-initialized. This calls the constructor of `tempClass`, which outputs "Inside temp class constructor".
2. After `tempClassobj` is instantiated, the assignment `tempClassobj = obj;` occurs. This uses the automatically provided copy assignment operator of `tempClass`, which doesn't output anything. So, the constructor of `tempClass` is called once during the default initialization of `tempClassobj`.

When you use the constructor with an initialization list (`myBaseClass(tempClass obj): tempClassobj(obj) {}`), this involves:

1. Directly initializing `tempClassobj` with `obj`. This passes `obj` to the copy constructor of `tempClass` rather than default-constructing `tempClassobj` first and then assigning it. This reduces the number of `tempClass` constructor calls to just the creation of the original `tempObj` in `main()`. There's no further constructor call for `tempClassobj` inside `myBaseClass` since it gets directly initialized with `obj`.

In summary, the first method calls the `tempClass` constructor twice due to default-initialization followed by assignment, while the constructor initialization list in the second method efficiently initializes `tempClassobj` with `obj` without additional constructions. This exemplifies how constructor initialization lists can provide performance benefits and why they are often preferred for initializing class members.*/

myBaseClass(tempClass obj): tempClassobj(obj){}
};
int main(){
    tempClass tempObj;
    myBaseClass obj(tempObj);
    return 0;
}
