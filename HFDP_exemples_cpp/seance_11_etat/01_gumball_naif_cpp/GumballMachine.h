#ifndef _GUMBALLMACHINE_H_
#define _GUMBALLMACHINE_H_

#define SOLD_OUT 0
#define NO_QUARTER 1
#define HAS_QUARTER 2
#define SOLD 3

#include <string>

class GumballMachine {
private:
  int m_count;
  int m_state;
  
public:
  GumballMachine() : GumballMachine(0) {}
  GumballMachine(int count);
  void insertQuarter();
  void ejectQuarter();
  void turnCrank();
  void dispense();
  void refill(int numGumBalls);
  friend std::ostream & operator<<(std::ostream& os, GumballMachine& gm);

};

#endif

