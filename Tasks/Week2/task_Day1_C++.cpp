/*Topic name: Starting of c++
(i)  constructor
(ii) types of constructor i.e default,parametrized,copy
(iii) destructor
(iv)  m/m managment in c++ i.e new and delete
(v)   Operator overloading of assignment operator
*/
// This file is created by: Priyanshu Sharma
#include<iostream>
using namespace std;
class Intern_Epam{
    string name;
    int id;
    string domain;

    public:
    Intern_Epam(){
        cout<<"Default constructor called"<<endl;
    }
    Intern_Epam(string name,int id,string domain){
        this->name = name;
        this->id = id;
        this->domain = domain;
        cout<<"Parametrized constructor called"<<endl;
    }
    Intern_Epam(Intern_Epam& obj){
        this->name = obj.name;
        this->id = obj.id;
        this->domain = obj.domain;
        cout<<"Copy constructor called"<<endl;
    }
    Intern_Epam& operator = (Intern_Epam& obj){
        if (this != &obj) { // Check for self-assignment
            name = obj.name;
            id = obj.id;
            domain = obj.domain;
        }
        cout << "Operator overloading of = operator" << endl;
        return *this;
    }
    void setdata(string name,int id,string domain){
        this->name = name;
        this->id = id;
        this->domain = domain;
    }
    void getdata(){
        cout<<"Name :"<<name<<endl;
        cout<<"Id   :"<<id<<endl;
        cout<<"Domain :"<<domain<<endl;
    }
    ~Intern_Epam(){
        cout<<"Destructor Called"<<endl;
    }
};
int main(){
    Intern_Epam I1;
    I1.setdata("Priyanshu Sharma",661436,"Cpp");
    I1.getdata();
    cout<<endl;

    Intern_Epam I2("Kratik Gupta",661438,"Java");
    I2.getdata();
    cout<<endl;

    Intern_Epam I3;
    I3 = I1;
    I3.getdata();
    cout<<endl;

    Intern_Epam I4;
    I4.setdata("Sparsh Aggarwal",661421,"Go Lang");
    I4.getdata();
    cout<<endl;
    

    Intern_Epam *I5 = new Intern_Epam();
    I5->setdata("Rohan",10000,"Python");
    I5->getdata();
    // here no destructor called directly bcoz object is created in heap section of m/m which only get free when programmer itself do it 
    delete(I5);// Now destructor execute;

    //This file is created by : priyanshu sharma


    return 0;

}
