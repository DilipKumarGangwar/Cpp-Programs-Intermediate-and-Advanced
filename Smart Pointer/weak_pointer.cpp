//Program to show the importance of WEAK POINTER in removing cyclic dependency

#include <bits/stdc++.h> 
using namespace std; 

//forward declaration
class Manager;
class Employee;

class Company{

    weak_ptr<Manager> manager;   //weak pointer
    weak_ptr<Employee> employee; //weak pointer
   public:
   void setManager(shared_ptr<Manager> m){
       manager = m;
   }

   void setEmployee(shared_ptr<Employee> e){
      employee = e;
   }

   ~Company(){
       cout<<"Destructing Company"<<endl;
   }

   //Uncomment this and comment above part,and You will find that NO DESTRUCTION will occur due to cyclic dependency
//    shared_ptr<Manager> manager;
//    shared_ptr<Employee> employee;
//    public:
//    void setManager(shared_ptr<Manager> m){
//        manager = m;
//    }

//    void setEmployee(shared_ptr<Employee> e){
//       employee = e;
//    }

//    ~Company(){
//        cout<<"Destructing Company"<<endl;
//    }
     

};
class Manager{
  shared_ptr<Company> company;
  public:
     Manager(shared_ptr<Company> com){
         company = com;
     }
     ~Manager(){
       cout<<"Destructing Manager"<<endl;
   }
};
class Employee{
    shared_ptr<Company> company;
  public:
     Employee(shared_ptr<Company> com){
         company = com;
     }
     ~Employee(){
       cout<<"Destructing Employee"<<endl;
   }

};

main(){
  
  shared_ptr<Company> company(new Company());
  shared_ptr<Manager> manager (new Manager(company));  //Manager will now point to Company Object
  shared_ptr<Employee> employee (new Employee(company)); //Employee will now point to Company Object

  //Now we are creating cyclic dependency, without weak pointers No DEstruction will occur
  company->setManager(manager);
  company->setEmployee(employee);

  //these answers will differe in case of use of weak pointersonly vs only using shared pointers
  cout<<company.use_count()<<endl; 
  cout<<manager.use_count()<<endl; 
  cout<<employee.use_count()<<endl; 
}