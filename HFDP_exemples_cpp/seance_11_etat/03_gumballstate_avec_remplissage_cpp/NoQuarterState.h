#ifndef _NOQUARTERSTATE_H_
#define _NOQUARTERSTATE_H_

#include "State.h"
#include "GumballMachine.h"

class GumballMachine;

class NoQuarterState : public State {
public:
  NoQuarterState(GumballMachine * gumballMachine)
    : m_gumballMachine(gumballMachine) {}
  virtual ~NoQuarterState() = default;
  
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
