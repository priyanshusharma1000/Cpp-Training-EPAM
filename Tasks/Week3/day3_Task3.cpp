//Topic : Friend class
//This file is created by : Priyanshu Sharma

#include<iostream>
using namespace std;

class Radius{
    int r;
    public:
    void setRadius(int r){
        this->r = r;
    }
    friend class Area;
};
class Area{
    public:
    float calArea(Radius& obj){
        return 3.14*obj.r*obj.r;
    }
};
int main(){
    Radius R;
    R.setRadius(3);
    Area A;
    cout<<"Area of circle is :"<<A.calArea(R);
    return 0;
}