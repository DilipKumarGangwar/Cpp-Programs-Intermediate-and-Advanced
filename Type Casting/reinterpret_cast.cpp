/* Reinterpret cast is a cast operator which is used to typecast any pointer to any other pointert while doing upcast,But donot use for downcast
 It may or may not work
*/

#include <iostream> 
using namespace std; 

class Bike { 
public: 

	// user wants to override this in 
	// the derived class 
	void ride() 
	{ 
		cout << "I ride bike" << endl; 
	} 
}; 

class Car  { 
public: 
	void ride()  
	{ 
		cout << "I ride Car" << endl; 
	} 
}; 

int main() 
{ 
    Bike *b=new Bike();
    Car *c=new Car();
    Car *c1 = reinterpret_cast<Car *>(&b); //casting Bike pointer to Car pointer
    c1->ride();          //may or may not work
	return 0; 
} 
