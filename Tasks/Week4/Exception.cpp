#include<iostream>
using namespace std;

class myClass{
    int x;
    int *ptr;
    public:
    myClass(){
        cout<<"Enter in the constructor"<<endl;
        try{
            x = 176;
            ptr = new int[5];
            for(int i=0;i<5;i++){
                ptr[i] = i;
            }

            throw runtime_error("exception occur in constructor of myClass");
            cout<<"constructor executed successfully"<<endl;//never execute
        }
        catch(const exception &e){
            cout<<"Exception :"<<e.what()<<endl;
        }
        cout<<"Out from the constructor"<<endl;
    }
    ~myClass(){
        cout<<"Destructor called"<<endl;
        delete ptr;
    }
};
int main(){
   try{
    myClass m1;

   }
   catch(...){
    cout<<"exception caught in main block"<<endl;
   }
   return 0;
}