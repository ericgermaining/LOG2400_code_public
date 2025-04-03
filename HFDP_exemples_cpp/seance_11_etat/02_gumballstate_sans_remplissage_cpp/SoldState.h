#ifndef _SOLDSTATE_H_
#define _SOLDSTATE_H_

#include "State.h"
#include "GumballMachine.h"

class GumballMachine;

class SoldState : public State {
public:
  SoldState(GumballMachine * gumballMachine)
    : m_gumballMachine(gumballMachine) {}
  virtual ~SoldState() = default;
  
  void insertQuarter();
  void ejectQuarter();
  void turnCrank();
  void dispense();
  void refill();
  
private:
  GumballMachine * m_gumballMachine;
  virtual std::ostream & stateToStream(std::ostream& os) override;
  
};

#endif
