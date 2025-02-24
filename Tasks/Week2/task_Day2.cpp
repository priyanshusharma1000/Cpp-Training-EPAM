<<<<<<< HEAD
/*Topic : class with default member functions
          constructor with different types of variables
          constructor overloading
          constructor and destructor with resources of type pointer
          array of object
          signifance of explicit keyword in constructor

*/

// This file is created by : Priyanshu Sharma

/*
   class do have its own member function by default and it is present in public section example default constructor , copy constructor
   but when we create our own functions then they got override
*/
#include<iostream>
using namespace std;
class Inter_Epam{
   string *name;
   int *id;
   string *domain;
   // static int No_of_obj;
   public:

   Inter_Epam(string name="XXX",int id=-1,string domain="XXX"){
      this->name = new string;
      this->id = new int;
      this->domain = new string;
      *(this->name) = name;
      *(this->id) = id;
      *(this->domain) = domain;
      // No_of_obj++;
   }
   Inter_Epam(string name,int id){
      this->name = new string;
      this->id = new int;
      this->domain = new string;
      *(this->name) = name;
      *(this->id) = id;
      *(this->domain) = "Cpp";
      // No_of_obj++;
   }
   /*
      In case of copy constructor if the data member of class is of pointer type then it create trouble because the shallow 
      copy will create problem in that case so we have to go for deep copy otherwise it leads to a condition when there is 
      change made by one object visible in another object which is unacceptable
   */ 
  Inter_Epam(Inter_Epam& obj){
   this->name = new string;
   this->id = new int;
   this->domain = new string;
   *(this->name) =*(obj.name);
   *(this->id) = *(obj.id);
   *(this->domain) = *(obj.domain);
   // No_of_obj++;
   // here we are doing deep copy
  }
   ~Inter_Epam(){
      delete name;
      delete id;
      delete domain;
   }
   void update(string name,int id,string domain){
      *(this->name) = name;
      *(this->id) = id;
      *(this->domain) = domain;
   }
   void display(){
      cout<<"Name :"<<*(this->name)<<endl<<"Id :"<<*(this->id)<<endl<<"Domain :"<<*(this->domain)<<endl;
   }
   
};
int main(){
   Inter_Epam I1("Priyanshu",661436,"Cpp");
   cout<<"Details of Intern I1 before update in I2"<<endl;
   I1.display();
   
   Inter_Epam I2(I1);
   cout<<"Details of Intern I2 before update :"<<endl;
   I2.display();
  
   I2.update("Kratik",666666,"Java");
    
   cout<<"Details of Intern I1 after update in I2"<<endl;
   I1.display();
   cout<<"Details of Intern I2 after update :"<<endl;
   I2.display();

//   cout<<"Total number of object created so far is :"<<Inter_Epam::No_of_obj<<endl;
  return 100;
=======
/*Topic : class with default member functions
          constructor with different types of variables
          constructor overloading
          constructor and destructor with resources of type pointer
          array of object
          signifance of explicit keyword in constructor

*/

// This file is created by : Priyanshu Sharma

/*
   class do have its own member function by default and it is present in public section example default constructor , copy constructor
   but when we create our own functions then they got override
*/
#include<iostream>
using namespace std;
class Inter_Epam{
   string *name;
   int *id;
   string *domain;
   // static int No_of_obj;
   public:

   Inter_Epam(string name="XXX",int id=-1,string domain="XXX"){
      this->name = new string;
      this->id = new int;
      this->domain = new string;
      *(this->name) = name;
      *(this->id) = id;
      *(this->domain) = domain;
      // No_of_obj++;
   }
   Inter_Epam(string name,int id){
      this->name = new string;
      this->id = new int;
      this->domain = new string;
      *(this->name) = name;
      *(this->id) = id;
      *(this->domain) = "Cpp";
      // No_of_obj++;
   }
   /*
      In case of copy constructor if the data member of class is of pointer type then it create trouble because the shallow 
      copy will create problem in that case so we have to go for deep copy otherwise it leads to a condition when there is 
      change made by one object visible in another object which is unacceptable
   */ 
  Inter_Epam(Inter_Epam& obj){
   this->name = new string;
   this->id = new int;
   this->domain = new string;
   *(this->name) =*(obj.name);
   *(this->id) = *(obj.id);
   *(this->domain) = *(obj.domain);
   // No_of_obj++;
   // here we are doing deep copy
  }
   ~Inter_Epam(){
      delete name;
      delete id;
      delete domain;
   }
   void update(string name,int id,string domain){
      *(this->name) = name;
      *(this->id) = id;
      *(this->domain) = domain;
   }
   void display(){
      cout<<"Name :"<<*(this->name)<<endl<<"Id :"<<*(this->id)<<endl<<"Domain :"<<*(this->domain)<<endl;
   }
   
};
int main(){
   Inter_Epam I1("Priyanshu",661436,"Cpp");
   cout<<"Details of Intern I1 before update in I2"<<endl;
   I1.display();
   
   Inter_Epam I2(I1);
   cout<<"Details of Intern I2 before update :"<<endl;
   I2.display();
  
   I2.update("Kratik",666666,"Java");
    
   cout<<"Details of Intern I1 after update in I2"<<endl;
   I1.display();
   cout<<"Details of Intern I2 after update :"<<endl;
   I2.display();

//   cout<<"Total number of object created so far is :"<<Inter_Epam::No_of_obj<<endl;
  return 100;
>>>>>>> 0644adbc15033299a5ac4359a5295f0c33d157f9
}