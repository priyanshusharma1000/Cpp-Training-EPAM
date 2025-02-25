// operator overloading 
// operator are overloaded to provide the functionality that is different from predefinded functionality 
// operator are of two types (i) unary operator -> require only one operand ex ++,--
// (ii) binary operator ->require two operand ex +,-,*,/


//unary operator example
/*
#include<iostream>
using namespace std;
class myClass{
  int a;
  public:
  void setdata(int a){
    this->a = a;
  }
  void operator ++ (){
    a = a - 1;
  }
  void display(){
    cout<<a<<endl;
  }
};
int main(){
    myClass m1;
    m1.setdata(7);
    m1.display();

    ++m1;
    m1.display();
    return 0;
}
*/
#include<iostream>
using namespace std;
class myClass{
  int a;
  public:
  void setdata(int a){
    this->a = a;
  }
  void operator + (myClass& obj){
    a = a + obj.a;
  }
  void display(){
    cout<<a<<endl;
  }
};
int main(){
    myClass m1,m2;
    m1.setdata(7);
    m2.setdata(7);
    m1.display();
    m1+m2;
    m1.display();
    return 0;
}
