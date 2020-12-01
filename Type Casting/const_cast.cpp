/* Program to show the use of const_cast cast operator*/

#include <iostream> 
using namespace std; 
  
int thirdparty(int *p){
    *p=*p+10;
    return *p;
}  
int main(void) 
{ 
    //Use 1: To remove constantness of const or volatile pointer/references
    int a1 = 40; 
    const int* b1 = &a1; 
   // char* c1 = (b1); // compiler error 
    int* c1 = const_cast<int *>(b1); //ok
    *c1 = 5; 
    cout<<"Value of a1="<<a1<<endl;
    cout<<"Value of c1="<<*c1<<endl;

    //Use 2: Used when third party libarary accepts non const parameter and we have const parameter
    cout<<"Vale returned by Third Party="<<thirdparty(const_cast<int*>(b1))<<endl; 
    cout<<"value of a1="<<a1;
    return 0; 
} 