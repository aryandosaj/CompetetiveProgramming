
#include<iostream> 
using namespace std; 
   
class Base 
{ 
public: 
    void show() { cout<<" In Base \n"; } 
}; 
   
class Derived: public Base 
{ 
public: 
    void show() { cout<<"In Derived \n"; } 
}; 

class Derived2: public Derived
{ 
public: 
    // void show() { cout<<"In Derived2 \n"; } 
}; 
   
int main(void) 
{ 
    Base *bp = new Derived2; 
    bp->show();  // RUN-TIME POLYMORPHISM 
    return 0; 
} 