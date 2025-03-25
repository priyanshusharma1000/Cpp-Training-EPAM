// Topic: constructor intialization list and its significance w.r.t reference variable , constructor chaining and when user defined data type is part of our class


/* (i) reference varaible usage
#include<iostream>
using namespace std;
class myClass{
 int x;
 int& y;// reference variable only intialize with this method
 public:
 myClass(int b): y(b),x(0){}
 myClass(int a,int b): x(a),y(b){}
 void display(){ cout<<"x:"<<x<<endl<<"y:"<<y;}
};
int main(){
 int p = 10;
 myClass m1(p);
 m1.display();
 return 0;
}
*/


/* constructor intializaion list use with inheritance*/
#include<iostream>
using namespace std;
class Base{
  int a;
  public:
  Base(int a){
    this->a = a;
    cout<<"Inside Base Class"<<endl;
  }
};
class Derived:public Base{
   public:
   Derived():Base(10){
    cout<<"Inside Derived Class"<<endl;
   }   
};
int main(){
    Derived d;
    return 0;
}


