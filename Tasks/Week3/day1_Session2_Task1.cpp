// Session taken by : Santhosh malay,
// only keyword that we can use with constructor is explicit when implicit intialization of instance of class is undesirable
/*
#include<iostream>
#include<utility> // make_pair defined in utility
using namespace std;
class myClass{
    int a;
    int b;
    public:
     myClass(pair<int,int>p): a(p.first),b(p.second){}

    void display(){
        cout<<a<<" "<<b<<endl;
    }
};
int main(){
    myClass m1 = make_pair(8,7); // implicit intialization , tip : implicit intialization of multiple argument in c++ is bit tricky
                       // as if we do myClass m1 = (8,7) the comma operator take last operand and which value is 7 and second 
                       // argument will become default zero so if we want to intialize multiple variable using implicit intialization then we have to make pair

    m1.display();
}

// usecase of explicit keyword with constructor :
// when we do not want that the implicit intialzation of data member then we use explicit keyword with constructor to avoid this
// here if we make explicit in front of constructor we wont be able to intialize object implicitly but we have option to intialize it directly 
// like myClass m1(7,8)

*/
// using explicit with copy constructor
#include<iostream>
using namespace std;

class myClass{
 int a;
 public:
 myClass(){}
 myClass(int a):a(a){}
 explicit myClass(myClass& obj){
    a = obj.a;
 }
 void display(){
    cout<<a<<endl;
 }
};
int main(){
    myClass m1(10);
    myClass m2(m1); // we cant be able to do myClass m2 = m1 as explicit stop the implicit intialization of variable;
    m2.display();
    return 0;
}