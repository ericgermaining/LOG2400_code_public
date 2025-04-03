#ifndef _GUMBALLMACHINE_H_
#define _GUMBALLMACHINE_H_

#include <string>
#include "State.h"
#include "SoldOutState.h"
#include "NoQuarterState.h"
#include "HasQuarterState.h"
#include "SoldState.h"

class GumballMachine {
public:
  GumballMachine() : GumballMachine(0) {}
  GumballMachine(int numberGumballs);
  virtual ~GumballMachine();
  void insertQuarter();
  void ejectQuarter();
  void turnCrank();
  State * getState() { return m_state; }
  State * getSoldOutState() { return m_soldOutState; }
  State * getNoQuarterState() { return m_noQuarterState; }
  State * getHasQuarterState() { return m_hasQuarterState; }
  State * getSoldState() { return m_soldState; }
  //void refill(int count);
  void setState(State * state) { m_state = state; }
  void releaseBall();
  int getCount() { return m_count; }
  friend std::ostream & operator<<(std::ostream& os, GumballMachine& gm);
  
private:
  State * m_soldOutState;
  State * m_noQuarterState;
  State * m_hasQuarterState;
  State * m_soldState;

  State * m_state;
  
  int m_count;

};

#endif

