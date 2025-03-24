#include <iostream>
#include<vector>
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
};
int main() {
vector<simple>nums;
nums.reserve(2);

nums.push_back(simple(1));

nums.push_back(simple(2));
cout<<"Resizing :"<<endl;
nums.push_back(simple(3));
return 0;
}