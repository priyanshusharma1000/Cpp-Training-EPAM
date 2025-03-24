#include <iostream>
using namespace std;
class simple{
    int *data;
    public:
    simple(int value):data(new int(value)){
        cout<<"parametrized constructor called with value :"<<*data<<endl;
    }
    ~simple(){
        if(data)
        delete data;
        cout<<"Destructor called"<<endl;
    }
    simple(simple &&other) noexcept {
        data = other.data;
        other.data = NULL;
        cout<<"Move constructor called"<<endl;
    }
    simple(const simple& other){
        data = new int(*other.data);
        cout<<"Copy constructor called"<<endl;
    }
    simple& operator=(simple&& other) noexcept{
        if(this!=&other)
        {
            data = other.data;
            other.data = NULL;
        }
        cout<<"Move assignment operator"<<endl;
        return *this;
    }
    void display(){
        cout<<*data<<endl;
    }
};
int main() {
  simple obj1(50);
  simple obj2(60);
  (obj2 = move(obj1)).display();
  return 0;
}