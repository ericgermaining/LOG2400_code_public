#include <iostream>
#include "GumballMachine.h"

int main()
{
  GumballMachine * gumballMachine = new GumballMachine(2);
  
  std::cout << *gumballMachine << std::endl;
  
  gumballMachine->insertQuarter();
  gumballMachine->turnCrank();
  
  std::cout << *gumballMachine << std::endl;
  
  gumballMachine->insertQuarter();
  gumballMachine->turnCrank();
  gumballMachine->ejectQuarter();
  gumballMachine->turnCrank();
  
  gumballMachine->refill(5);
  gumballMachine->insertQuarter();
  gumballMachine->turnCrank();
  
  std::cout << *gumballMachine << std::endl;
  
  delete gumballMachine;
  return 0;
}
