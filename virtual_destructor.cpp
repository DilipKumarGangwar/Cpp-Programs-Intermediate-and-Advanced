/* Program to show the use of virtual destrcutor
It prevents Memory leak.
Best Practice: Use virtual destrcutor whenver a class has even at leat one virtual function
*/

#include <bits/stdc++.h> 
using namespace std; 

class Base{
   public:
   Base(){
       cout<<"Base Constructor"<<endl;
   }
   //Virtual Destructor
   //if we remove virtual keyword here, then only Base object is deleted
   //Derived object is not deleted leading to memory leak
   virtual ~Base(){                                
       cout<<"Base Destructor"<<endl;
   }
};

class Derived: public Base{
   public:
   Derived(){
       cout<<"Derived Constructor"<<endl;
   }
   ~Derived(){
       cout<<"Derived Destructor"<<endl;
   }
};  
int main(){
   Base *b= new Derived();
   delete b;  //deleting everything via base class pointer
   return 0;

}