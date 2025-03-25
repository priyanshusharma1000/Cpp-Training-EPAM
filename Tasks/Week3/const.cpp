// topic: const keyword in cpp
// const function does not have power to modify or intialize the data member of class becouse in non const member function compiler create a this pointer which is pointing to the current object,but in case of non const member function this pointer is pointing to the current object 

// in non const member function when we do any assignment of like this p=q it is converted to this->p = q implicitly by compiler but in case of const member function this is point to const and if we do like this p = q then compiler make it this->p = q which is equivalent to NULL->p = q we get error through compiler 


// const data member is intialized either in directly class intialization or through the use of constructor intialization method

#include<iostream>
using namespace std;;

class myClass{
    int p;
    int q;
    public:
    void nonconstfn(int p,int q){
        this->p = p;
        this->q = q;  // in case of non const member fn this pointer points to current object
    }
     void constfn(int p,int q) const {
    //     this->p = p;
    //     this->q = q; // here this is pointing to const so here in const function we can only read the values, no intialization and modification allowed
      cout<<"Const function called"<<endl;
     }
     int pvalue() const{
        return p;
     }
    void display(){
        cout<<"P : "<<p<<endl<<"Q : "<<q;
    }
};
int main(){
    myClass m1;
    m1.nonconstfn(4,5);
    m1.display();
    cout<<endl<<m1.pvalue()<<endl;
    return 0;
}

