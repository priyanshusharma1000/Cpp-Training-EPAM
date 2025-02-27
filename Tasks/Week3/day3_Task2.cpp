//Topic : Friend function
// concept: A special function which is responsible for accessing the private data member of class
// which breaches the concept of abstraction and encapsulation and hence that is why cpp is not 100% oops programming language 
//This file is created by : Priyanshu Sharma
#include<iostream>
using namespace std;

class complex{
  int real;
  int img;

  public:
  complex():real(0),img(0){}
  void setdata(int real,int img){
    this->real = real;
    this->img = img;
  }  
  void getdata(){
    cout<<"Your Complex number is :"<<real<<"+ i"<<img<<endl;
  }
  friend complex sumcomplex(complex &o1,complex &o2);
};

complex sumcomplex(complex &o1,complex &o2){
    complex ans;
    ans.real = o1.real + o2.real;
    ans.img = o1.img + o2.img;
    return ans;
}

int main(){
    complex o1,o2,o3;
    o1.setdata(3,4);
    o1.getdata();

    o2.setdata(5,6);
    o2.getdata();

    o3 = sumcomplex(o1,o2);
    cout<<"Resultant after adding above two complex number is :"<<endl;
    o3.getdata();

    return 0;
}