// Deep Copy
// Shallow copy create problem in case of pointer type of variable so we have to go for deep copy in that case

#include<iostream>
using namespace std;

class myClass{
    int* arr;
    int n;
    public:

    myClass(int n){
        this->n = n;
        arr = new int(n);
    }
    
    ~myClass(){
        delete[] arr;
    }
    myClass(myClass &obj){
        // here we are doing deep copy
        //rather than copying the value of pointer we are creating new memory in heap and then copying the content 
        this->n = obj.n;
        arr = new int(n);
        for(int i=0;i<n;i++){
            arr[i] = obj.arr[i];
        }
    }
    void setdata(){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    }

   void display(){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   }

   void update(){
    for(int i=0;i<n;i++){
        arr[i] = 176;
    }
   }
};
int main(){
    myClass m1(5);
    m1.setdata();
    m1.display();

    myClass m2(m1);
    m2.display();
    m2.update();
    m2.display();

    // although we have update in m2 but it reflect in m1 beacuse compiler by default do shallow copy which is not desirable

    m1.display();
    
    return 0;
}