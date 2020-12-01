/* Dynamic cast is a cast operators which says that type checking will be done at run time

1. It is used in polymorphic call
2. At least one virtual function is needed to be there in a class
3. Used especially to check wrong downcast
*/
#include <iostream> 
using namespace std; 

class Base { 
public: 

	// user wants to override this in 
	// the derived class 
	 virtual void func() 
	{ 
		cout << "I am in base" << endl; 
	} 
}; 

class derived1 : public Base { 
public: 
	void func() override 
	{ 
		cout << "I am in derived class1" << endl; 
	} 
}; 

class derived2 : public Base { 
public: 
	void func() override 
	{ 
		cout << "I am in derived class2" << endl; 
	} 
}; 
int main() 
{ 
    derived1 dp1;
    Base bp1;
	Base *bp2 =dynamic_cast<Base *>(&dp1);    //Valid upcast
	derived1 *dp2 = dynamic_cast<derived1 *>(bp2);  // Valid downcast
    derived1 *bp3 =dynamic_cast<derived1 *>(&bp1);  //Error: wrong downcast,fail at runtime, So will return nullptr
    if(bp3==nullptr){   //this will be printed on running the program
        cout<<"Null";
    }
    else{
        cout<<"Not Null";
    }
    
	return 0; 
} 
