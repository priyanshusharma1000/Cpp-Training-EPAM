// smart pointers 
// they are wrapper to raw pointer
// in case of raw pointer due to exception it leads to memory leak so smart pointer is better way to handle memory leak as it automatically call the delete when it goes out of bound 

#include<iostream>
#include<memory>
using namespace std;
class myClass{
 public:
 myClass(){
    cout<<"constructor invoked"<<endl;
 }
 ~myClass(){
    cout<<"destructor invoked"<<endl;
 }
};

int main(){
    // unique_ptr<int>ptr(new int(5));
    unique_ptr<int>unptr1 = make_unique<int>(25);
    cout<<*unptr1<<endl;

    unique_ptr<int>unptr2 = move(unptr1);
    cout<<*unptr2<<endl;
    //if we try to do *unptr1 here will get error bcoz now the ownership is tranfereed to unptr2 whereas  unptr1 is now pinting to null
    //cout<<*unptr1; error here
    
    unique_ptr<myClass>ptr = make_unique<myClass>();



    // shared ptr
    // memory location may have multiple owners and it will exist till there exist atleast one ptr pointing to it
    shared_ptr<myClass>sptr = make_unique<myClass>();
    cout<<"shared count:"<<sptr.use_count()<<endl;
    {
    shared_ptr<myClass>sptr2 = sptr;
    cout<<"shared count:"<<sptr.use_count()<<endl;
    }
    cout<<"shared count:"<<sptr.use_count()<<endl;




    system("pause>nul");



    return 0;
}

