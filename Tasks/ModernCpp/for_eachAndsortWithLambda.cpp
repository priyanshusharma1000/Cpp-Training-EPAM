#include<iostream>
#include<algorithm>
#include<vector>
class person{
    public:
    std::string name;
    int age;
    person(std::string arg1,int arg2):name(arg1),age(arg2){}
    void print() const { std::cout << name << " is " << age << " years old\n"; }
};
int main(){
    std::vector<int>nums{1,4,5,3,2,0};
    for_each(nums.begin(),nums.end(),[](int& x){
        x*=2;
    });
    for_each(nums.begin(),nums.end(),[](int a){
        std::cout<<a<<" ";
    });
    sort(nums.begin(),nums.end(),[](int a,int b)->bool{
       return a>=b;
    });
    std::cout<<std::endl;
    for(auto i:nums)
    std::cout<<i<<" ";
    
    
    auto fn = [](bool flag)->int{
        if(flag)
        return 3.3f;
        else
        return 3;
    };
    std::cout<<std::endl;
    std::cout<<fn(1);
    
    
    std::cout<<std::endl;
    std::vector<person>V{{"kratik",21},{"Alice",29},{"Bob",30},{"priyanshu",22}};
    for_each(V.begin(),V.end(),[](person &p){
        p.print();
    });
    
    std::cout<<std::endl;
    
    
    sort(V.begin(),V.end(),[](person &p1,person &p2){
        return p1.name<= p2.name;
    });
    
    for_each(V.begin(),V.end(),[](person &p){
        p.print();
    });
return 0;
}