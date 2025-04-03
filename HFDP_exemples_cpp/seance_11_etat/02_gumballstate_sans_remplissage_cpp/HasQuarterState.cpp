#include <iostream>
#include "HasQuarterState.h"

void HasQuarterState::insertQuarter() {
  std::cout << "Vous ne pouvez pas inserer une seconde piece." << std::endl;
}

void HasQuarterState::ejectQuarter() {
  std::cout << "Piece retournee." << std::endl;
  m_gumballMachine->setState(m_gumballMachine->getNoQuarterState());
}

void HasQuarterState::turnCrank() {
  std::cout << "Et ca tourne..." << std::endl;
  m_gumballMachine->setState(m_gumballMachine->getSoldState());
}

void HasQuarterState::dispense() {
  std::cout << "Aucune gomme livree." << std::endl;
}

void HasQuarterState::refill() { }

std::ostream & HasQuarterState::stateToStream(std::ostream& os) {
  return os << "en attente d'un tour de manivelle.";
}
