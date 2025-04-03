#ifndef _SOLDOUTSTATE_H_
#define _SOLDOUTSTATE_H_

#include "State.h"
#include "GumballMachine.h"

class GumballMachine;

class SoldOutState : public State {
public:
  SoldOutState(GumballMachine * gumballMachine)
    : m_gumballMachine(gumballMachine) {}
  virtual ~SoldOutState() = default;
  
  void insertQuarter();
  void ejectQuarter();
  void turnCrank();
  void dispense();
  //void refill();
  
private:
  GumballMachine * m_gumballMachine;
  virtual std::ostream & stateToStream(std::ostream& os) override;
};

#endif
