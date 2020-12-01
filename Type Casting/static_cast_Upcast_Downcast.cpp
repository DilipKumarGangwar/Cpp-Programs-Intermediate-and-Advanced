/* Static cast is a cast operator which says that type checking will be done at Compile time

Use it while doing upcast,But donot use for downcast
Use dynamic_cast<> for wrong Downcast
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
	Base *bp2 =static_cast<Base *>(&dp1);    //Valid upcast
	derived1 *dp2 = static_cast<derived1 *>(bp2);  // Valid downcast
    derived1 *bp3 =static_cast<derived1 *>(&bp1);  //It won't be catch at compiled time and it is wrong downcast.
                                                   // So it will return run successfully
                                                   //For wrong downacst, we should use dynamic_cast<>
    if(bp3==nullptr){   //this will be printed on running the program
        cout<<"Null";
    }
    else{
        cout<<"Not Null";
    }
    
	return 0; 
} 
