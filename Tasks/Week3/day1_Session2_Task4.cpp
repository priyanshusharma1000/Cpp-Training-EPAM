// Static data member and static member function 
// static data member is also known as class variable and it is only intialize only one time and share by all the instance of class
// its memory allocated in common staging area
// static member function has power to access only static data members

// here is program which keep track how many instances of class created so far
#include<iostream>
using namespace std;
class instCount{
 static int cnt;
 public:
 instCount(){
    cnt++;
 }
 static int count(){
    return cnt;
 }
};
int instCount::cnt = 0;
int main(){
    instCount i1;
    cout<<"Number of objects of class so far :"<<i1.count()<<endl;

    instCount i2;
    cout<<"Number of objects of class so far :"<<i2.count()<<endl;

    instCount i3;
    cout<<"Number of objects of class so far :"<<i2.count()<<endl;
    
    return 0;
}