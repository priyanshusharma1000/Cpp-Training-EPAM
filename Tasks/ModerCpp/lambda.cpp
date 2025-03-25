#include<iostream>
#include<typeinfo>
using namespace std;
class unNamed{
    public:
    int operator()(int a,int b){
        return a+b;
    }
};
template<typename T,int size,typename callback>
void forEach(T(&arr)[size],callback operation){
    for(int i=0;i<size;i++){
        operation(arr[i]);
    }
}

// why offset is not incremented if pass by value but incremented if pass by refrence and if we want to increment it when pass by value we need to use mutable with it 
template<typename T>
class _unNamed{
    int offset;
    public:
  _unNamed(int off):offset(off){}
  void operator()(T& a){
    a+=offset;
    ++offset;
  }
};

int main(){
    // this lambda expression is automatically invoked as we call it 

    [](){
      cout<<"Inside the body of lambda expression"<<endl;
    }();
    
    // this is called when we make a call
    auto fn = [](){
        cout<<"Inside the body of lambda expression"<<endl;
    };
    fn();



    // lambda to add two numbers
    auto sum = [](int x,int y) noexcept{
       return x + y;
    };
    cout<<"sum is :"<<sum(5,2)<<endl;


    // proof that same is implemented as functor by compiler -> will perform the same operation using functor lets see
    unNamed u;
    cout<<"sum is :"<<u(5,2)<<endl;

//``````````````````````````````````````````````````````//
  
int arr[]{1,6,8,4,0};
forEach(arr,[](auto x){
   cout<<x<<" ";
});
cout<<endl<<endl;
// if we want to add offset to each value of array then
int offset = 5;
forEach(arr,[&](auto&x){
    x+=offset;
    offset++;
});
forEach(arr,[](auto x){
    cout<<x<<" ";
});

    





    return 0;
}