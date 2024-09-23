
#include <iostream>

using namespace std;

class Base {

public :
  
  virtual ~Base() { std::cout << "Base destructor called" << endl ;  } ;

  virtual void method() = 0;
  
};

class Derived : public Base {
 
public : 

  ~Derived() { std::cout << "Derived destructor called" << endl ; }

  void method() { std::cout << "Derived::method() called" << endl ; }

};


int main() {

  Base * myclass = new Derived() ;

  myclass->method();

  delete myclass;

}

