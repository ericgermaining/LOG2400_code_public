#include <iostream>
#include "GumballMachine.h"

GumballMachine::GumballMachine(int numberGumballs) :
  m_soldOutState(new SoldOutState(this)),
  m_noQuarterState(new NoQuarterState(this)),
  m_hasQuarterState(new HasQuarterState(this)),
  m_soldState(new SoldState(this)),
  m_state(m_soldOutState),
  m_count(numberGumballs)
{
  if (m_count > 0) {
    m_state = m_noQuarterState;
  }
}

GumballMachine::~GumballMachine() {
  m_state = nullptr;
  delete m_soldState;
  delete m_hasQuarterState;
  delete m_noQuarterState;
  delete m_soldOutState;
}

void GumballMachine::insertQuarter() {
  m_state->insertQuarter();
}
  
void GumballMachine::ejectQuarter() {
  m_state->ejectQuarter();
}
  
void GumballMachine::turnCrank() {
  m_state->turnCrank();
  m_state->dispense();
}

void GumballMachine::releaseBall() {
  std::cout << "Une gomme balloune s'en vient..." << std::endl;
  if(m_count > 0)
    m_count--;
}
  
void GumballMachine::refill(int count) {
  m_count += count;
  std::cout << "Remplissage termine; le decompte des gommes ballounes est desormais de: " << m_count << std::endl;
  m_state->refill();
}

std::ostream & operator<<(std::ostream& os, GumballMachine& gm) {
  os << std::endl << "Vous etes dans la Machine a gommes ballounes." << std::endl;
  os << "En stock: " << gm.m_count << " gomme";
  if (gm.m_count != 1) {
    os << "s";
  }
  os << std::endl << "La machine est " << *(gm.m_state) << std::endl;
  return os;
}

