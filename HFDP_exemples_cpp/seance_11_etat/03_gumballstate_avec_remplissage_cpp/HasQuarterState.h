#ifndef _HASQUARTERSTATE_H_
#define _HASQUARTERSTATE_H_

#include "State.h"
#include "GumballMachine.h"

class GumballMachine;

class HasQuarterState : public State {
public:
  HasQuarterState(GumballMachine * gumballMachine)
    : m_gumballMachine(gumballMachine) {}
  virtual ~HasQuarterState() = default;
  
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
