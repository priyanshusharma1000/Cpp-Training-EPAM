//Topic: Polymorphism 
// compile time polymorphism : function overloading and operator overloading
// concept of NAME MANGLING  and importance of extern while using c library in cpp 
#include<iostream>
using namespace std;
class Employee_Epam{
   int id;
   string E_type;
   string name;
   string domain;

   public:
   void setdata(int id,string E_type,string name,string domain){
    this->id = id;
    this->E_type = E_type;
    this->name = name;
    this->domain = domain;
   }
   void setdata(int d,string name,string domain){
      this->id = id;
      this->E_type = "Intern";
      this->name = name;
      this->domain = domain;
   }
   void getdata(){
      cout<<"Name :"<<name<<endl;
      cout<<"Id :"<<id<<endl;
      cout<<"E_type :"<<E_type<<endl;
      cout<<"Domain :"<<domain<<endl;
   }
};
int main(){
   Employee_Epam E1,E2;
   E1.setdata(552134,"Full time","Santhosh Malay","Cpp");
   E1.getdata();

   E2.setdata(664136,"Priyanshu sharma","Cpp");
   E2.getdata();
   
   return 0;
}