// virtual distructor is mandatory to prevent memory leaks otherwise if we have base class pointer holding the address of object of derived class after the completion of program only the destructor of base class is called not the derived class so leaving the memory allocated for derived class as it is hence it is necessory to make the virtual destructor .

// execution of constructor and destructor will occur in this manner
/*
  Base class constructor 
  Derived class constructor 
  Derived class destructor 
  Base class Destructor
*/

/*
We can't be able to create virtual constructor as soon as compiler comes to know that particular class has a virtual member function then it will immediatly create a virtaul table for it and create a virtual pointer in it which is pointing to the vtable of that class and the code of vpointer is put in the defination of constructor of that class so there is no point that there is the existence of virtual constructor
*/
#include <iostream>
using namespace std;
class Base{
    public:
    Base(){
        cout<<"Base class constructor"<<endl;
    }
    virtual ~Base(){
        cout<<"Base class destructor"<<endl;
    }
};
class Derived:public Base{
     public:
        Derived(){
        cout<<"Derived class constructor"<<endl;
    }
    virtual ~Derived(){
        cout<<"Derived class destructor"<<endl;
    }
};

int main() {
   Base* bptr = new Derived();
   delete bptr;

    return 0;
}