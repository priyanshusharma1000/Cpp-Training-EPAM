//topic: chaining of assignment operator
//this file is created by: Priyanshu Sharma
#include<iostream>
using namespace std;
class myClass{
  int x;
  float* y;

  public:
  myClass(){
      y = new float;
  }

  myClass operator = (const myClass &obj){
    if(this == &obj)
    return obj;

    this->x = obj.x;
    *(this->y)= *(obj.y);
    return *this;
  }

  void setvalue(int arg1,float arg2){
    x = arg1;
    *y = arg2;
  }
  void display(){
    cout<<"X: "<<x<<" "<<"Y: "<<*y<<endl;
  }
};

int main(){
    myClass m1,m2,m3;
    m1.setvalue(1,2.2);
    m2.setvalue(2,3.3);
    m3.setvalue(3,4.4);

    m1.display();
    m2.display();
    m3.display();

    m1 = m2 = m3;

    cout<<"After chaining of assignment operator the updated value of objects are"<<endl;

    m1.display();
    m2.display();
    m3.display();

    return 0;
}