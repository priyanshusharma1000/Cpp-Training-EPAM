// Topic : Copy constructor , shallow copy
// if we cant create our own copy constructor then compiler create it itself called copy constructor and do shallow copy
// it is used when a new object is creaed from existing object and, want the copy of all values of data member of existing object into new object

#include<iostream>
using namespace std;

class myClass{
    int x;
    float f;

    public:
    void setdata(int x,float f){
        this->x = x;
        this->f = f;
    }
    myClass(){}
    myClass(myClass &obj){
        if(this==&obj)
        return;

        this->x = obj.x;
        this->f = obj.f;
    }
    void display() const{
        cout<<"X :"<<x<<endl<<"F :"<<f<<endl;
    }
};
int main(){
    myClass m1;
    m1.setdata(4,5);
    myClass m2 = m1;
    m2.display();
    return 0;
}

// Here in case of primitive data member shallow copy offered by default constructor does not create any problem ,and the shallow copy we do when we create own copy constructor also dont create any problem

// but when we have pointer variable as the data member of class than shallow copy create a problem, so we have to go for deep copy
