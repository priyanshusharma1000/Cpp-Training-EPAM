// topic: overload the subscript operator 
// this file is created by : Priyanshu Sharma

#include<iostream>
using namespace std;
class myClass{
    int x;
    public:
    void setvalue(int arg){x=arg;}
     int operator [](int p){
        return x;
    }
};
int main(){
    myClass m[10];
    m[1].setvalue(14);

    cout<<m[1][1];
}