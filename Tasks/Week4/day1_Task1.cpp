// topic: prefix and postfix operator overloading 
// concept : to mimic the  real defination of postfix operator we need to create a temp object and then perform the task hence it create n number of temp object so it is always recommended to use prefix operator in case of container as compared to postfix operator ,bcoz prefix operator provide better optimize result as compared to postfix

#include<iostream>
using namespace std;

class myClass{
 int x;
 public:
 myClass(){}
 void setvalue(int x){
    this->x = x;
 }
 myClass operator ++ (){
    x++;
    return *this;
 }
 myClass operator ++(int x){
    myClass temp = *this;
    ++x;
    return temp;
 }
 int getvalue(){
    return x;
 }
};
int main(){
    myClass m1;
    m1.setvalue(0);
    cout<<m1.getvalue()<<endl;
    ++m1;
    cout<<m1.getvalue()<<endl<<endl;

    myClass m2;
    m2.setvalue(0);
    cout<<m2.getvalue()<<endl;;
    m2++;
    cout<<m2.getvalue()<<endl;;

    return 0;
}