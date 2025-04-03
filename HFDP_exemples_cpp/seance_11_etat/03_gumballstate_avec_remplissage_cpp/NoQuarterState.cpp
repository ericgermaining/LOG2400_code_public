#include <iostream>
#include "NoQuarterState.h"

void NoQuarterState::insertQuarter() {
  std::cout << "Piece Inseree." << std::endl;
  m_gumballMachine->setState(m_gumballMachine->getHasQuarterState());
}

void NoQuarterState::ejectQuarter() {
  std::cout << "Vous n'avez pas mis de piece." << std::endl;
}

void NoQuarterState::turnCrank() {
  std::cout << "Vous n'avez pas mis de piece." << std::endl;
}

void NoQuarterState::dispense() {
  std::cout << "Il faut payer d'abord." << std::endl;
}

void NoQuarterState::refill() { }

std::ostream & NoQuarterState::stateToStream(std::ostream& os) {
  return os << "en attente d'une piece de monnaie.";
}
