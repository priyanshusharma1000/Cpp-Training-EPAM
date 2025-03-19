// Assignment operator
// This file is created by :Priyanshu Sharma
// this is used for two already created object
// compiler provide default assignment operator
// we can also create our own overloaded assignment operator to provide the functionality which is different from its predefined functionality

#include<iostream>
using namespace std;
class myClass{
int x;
int* y;
public:
myClass(){
    y = new int;
}
myClass operator = (myClass &obj){
   this->x = obj.x;
   *y = *(obj.y);
}
void setvalue(int arg1,int arg2){
    x = arg1;
    *y = arg2;
}
void  display(){
    cout<<"X: "<<x<<" "<<"Y: "<<*y<<endl;
}
};
int main(){
    myClass m1;
    m1.setvalue(1,2);
    m1.display();

    myClass m2;
    m2.setvalue(3,4);
    m2.display();

    m1 = m2;
    cout<<"After overloaded assignment operator the modified value of m1 is "<<endl;
    m1.display();

    return 0;

}