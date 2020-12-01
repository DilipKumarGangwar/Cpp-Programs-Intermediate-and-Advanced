#include<iostream> 
using namespace std; 

main(){

    //Use 1: For better readability and tell 2nd person explicitly as what you are doing
    float a=20.5;
    int b=static_cast<int>(a);
    cout<<a<<" "<<b;

    //Use 2: To warn against dangerous conversions 
    char c;
    int *p=(int *)&c; //compiled, but can fail at run time or dangerous to use
    *p=5;
    cout<<*p;
    int *p=static_cast<int *>(&c); //by static cast, easy to know it . Again FAIL at compile time

    return 0;
}