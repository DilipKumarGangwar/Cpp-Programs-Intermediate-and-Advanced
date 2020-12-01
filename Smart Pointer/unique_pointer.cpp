//Program to show the concept of UNIQUE POINTER 

#include <bits/stdc++.h> 
using namespace std; 

class Foo{  
  int x;
  public:
  Foo(int x):x(x){}
  int getX(){
      return x;
  }
  ~Foo(){
      cout<<"Destructor"<<endl;
  }

};
main(){
  Foo *p=new Foo(20);
  cout<<p->getX()<<endl;
  //delete p    if we do not write this the memory pointed by p is not deallocated (giving memory leak)

  unique_ptr<Foo> p1(new Foo(30)); // One way to make shared object
  cout<<p1->getX()<<endl;
  cout<<"Address of managed object by p1="<<p1.get()<<endl;                   //gives address of managed object by p1

  unique_ptr<Foo> p2=make_unique<Foo>(40);  //another way to make shared object
  cout<<p2->getX()<<endl;
   
  Foo *p3=p2.get();         //gives address of managed object by p2
  cout<<"Address stored in p3="<<p3<<endl ;
  //cout<<p1.use_count();   unique ptr has no use_count(); 
   
  unique_ptr<Foo> p4=move(p2); //p2 is transfering  ownership of managed object to p4
                               // Now p4 is pointing to object previously pointed by p2
  cout<<p4.get()<<endl;              //getting adddress of managed object by p4, it will be same as previously we got for p2
  
  cout<<"P1 points to address="<<p1.get()<<endl;
  Foo *p5 = p1.release();   //gives address of managed object by p1 and p1 is no longer pointing to its managed object
  cout<<"Address in p5="<<p5<<endl;   //same as of p1

  p4.reset(p5);    //p4 is pointing to p5's managed object and p5 link is broken
  cout<<"Address of managed object by p4="<<p4.get()<<endl;
  return 0;
}