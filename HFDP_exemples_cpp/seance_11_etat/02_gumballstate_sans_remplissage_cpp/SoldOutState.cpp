#include <iostream>
#include "SoldOutState.h"

void SoldOutState::insertQuarter() {
  std::cout << "La machine est en rupture de stock." << std::endl;
}

void SoldOutState::ejectQuarter() {
  std::cout << "Vous n'avez pas mis de pièce." << std::endl;
}

void SoldOutState::turnCrank() {
  std::cout << "La machine est vide." << std::endl;
}

void SoldOutState::dispense() {
  std::cout << "Aucune gomme n'a ete livree." << std::endl;
}

//void SoldOutState::refill() { 
// Completez le code ici.
//}

std::ostream & SoldOutState::stateToStream(std::ostream& os) {
  return os << "en rupture de stock";
}
