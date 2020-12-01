/*Program to show the concept of Virtual Inheritance
It Solves the Diamond Problem in C++(Ambiguity Problem)
      A
   B     C
      D
Here ,Class B and C inherits from A and all the constructors/dadat and methods in A will come in both B and C. When D
inherits from B and C(via Multiple inheritance) ,then compiler faces ambiguity as there are two copies of everything
coming from B and C.
To remove this ambiguity , virtual keyword is used with B and C and those becomes virtual Base classes
Overall , we did Virtual Inheritance         
  
*/

#include <bits/stdc++.h> 
using namespace std; 

class A{
   public:
   A(){
       cout<<"A's Constructor"<<endl;
   }
   void fun(){
       cout<<"Inside A"<<endl;
   }

};

class B:virtual public A{};  //Virtual Base class  (Without virtual keyword,ambiguity willl be there)
class C:virtual public A{};  //Virtual Base class
class D:public B, public C{};

int main(){
   D d;
   d.fun();
   return 0;

}