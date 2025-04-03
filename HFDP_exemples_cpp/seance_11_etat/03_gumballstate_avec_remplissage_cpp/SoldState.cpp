#include <iostream>
#include "SoldState.h"

void SoldState::insertQuarter() {
  std::cout << "Livraison en cours, veuillez patienter" << std::endl;
}

void SoldState::ejectQuarter() {
  std::cout << "Vous avez deja tourne la manivelle." << std::endl;
}

void SoldState::turnCrank() {
  std::cout << "On ne tourne qu'une seule fois." << std::endl;
}

void SoldState::dispense() {
  m_gumballMachine->releaseBall();
  if(m_gumballMachine->getCount() > 0)
    m_gumballMachine->setState(m_gumballMachine->getNoQuarterState());
  else {
    std::cout << "Flute, plus de gommes ballounes!" << std::endl;
    m_gumballMachine->setState(m_gumballMachine->getSoldOutState());
  }
}

void SoldState::refill() { }

std::ostream & SoldState::stateToStream(std::ostream& os) {
  return os << "en cours de livraison d'une gomme balloune.";
}
