// Topic Name: Run time polymorhism using function overriding and through the use of virtual function 
// This file is created by : Priyanshu Sharma
// Run time Polymorhism basically referes to the dynamic binding where the linking of member function with object will be done at run time means which function will execute will decide at run time
#include<iostream>
using namespace std;
class Base{
    public:
    virtual void show(){
        cout<<"show function of Base class"<<endl;
    }
    void display(){
        cout<<"display function of Base class"<<endl;
    }
};

class Derived : public Base{
    public:
    void show(){
        cout<<"show function of Derived class"<<endl;
    }
    void display(){
        cout<<"display function of Derived class"<<endl;
    }
};
int main(){
    Base *bptr = new Derived();
    bptr->display();
    bptr->show();
    return 0;
}

// here the binding of function with object is done at run time so it is example of run time polymorphism