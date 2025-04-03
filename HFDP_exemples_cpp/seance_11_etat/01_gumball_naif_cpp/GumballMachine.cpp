#include <iostream>
#include "GumballMachine.h"

GumballMachine::GumballMachine(int count)
  : m_count(count), m_state(SOLD_OUT) {
  if (count > 0) {
    m_state = NO_QUARTER;
  }
}

void GumballMachine::insertQuarter() {
  if (m_state == HAS_QUARTER) {
    std::cout << "Vous ne pouvez ajouter de piece car une piece est deja presente." << std::endl;
  } else if (m_state == NO_QUARTER) {
    m_state = HAS_QUARTER;
    std::cout << "Votre piece a ete inseree." << std::endl;
  } else if (m_state == SOLD_OUT) {
    std::cout << "Rupture de stock, vous ne pouvez ajouter de piece." << std::endl;
  } else if (m_state == SOLD) {
    std::cout << "Veuillez patienter, une gomme est en cours de livraison." << std::endl;
  }
}
  
void GumballMachine::ejectQuarter() {
  if (m_state == HAS_QUARTER) {
    std::cout << "Piece retournee." << std::endl;
    m_state = NO_QUARTER;
  } else if (m_state == NO_QUARTER) {
    std::cout << "Vous n'avez pas insere de piece." << std::endl;
  } else if (m_state == SOLD) {
    std::cout << "Desole, vous avez deja tourne la manivelle." << std::endl;
  } else if (m_state == SOLD_OUT) {
    std::cout << "Vous n'avez pas insere de piece." << std::endl;
  }
}
  
void GumballMachine::turnCrank() {
  if (m_state == SOLD) {
    std::cout << "Vous avez deja tourne la manivelle." << std::endl;
  } else if (m_state == NO_QUARTER) {
    std::cout << "La piece est manquante." << std::endl;
  } else if (m_state == SOLD_OUT) {
    std::cout << "Desole, il ne reste plus de gommes." << std::endl;
  } else if (m_state == HAS_QUARTER) {
    std::cout << "Et ca tourne..." << std::endl;
    m_state = SOLD;
    dispense();
  }
}
  
void GumballMachine::dispense() {
  if (m_state == SOLD) {
    std::cout << "Voici votre gomme balloune!" << std::endl;
    m_count--;
    if (m_count == 0) {
      std::cout << "Oups, desole, il ne reste plus de gommes." << std::endl;
      m_state = SOLD_OUT;
    } else {
      m_state = NO_QUARTER;
    }
  } else if (m_state == NO_QUARTER) {
    std::cout << "Vous devez d'abord payer." << std::endl;
  } else if (m_state == SOLD_OUT) {
    std::cout << "Pas de gomme livree." << std::endl;
  } else if (m_state == HAS_QUARTER) {
    std::cout << "Pas de gomme livree." << std::endl;
  }
}
  
void GumballMachine::refill(int numGumBalls) {
  m_count = numGumBalls;
  m_state = NO_QUARTER;
}

std::ostream & operator<<(std::ostream& os, GumballMachine& gm) {
  os << std::endl << "Vous etes dans la Machine a gommes ballounes." << std::endl;
  os << "En stock: " << gm.m_count << " gomme";
  if (gm.m_count != 1) {
    os << "s";
  }
  os << std::endl << "La machine est ";
  if (gm.m_state == SOLD_OUT) {
    os << "en rupture de stock.";
  } else if (gm.m_state == NO_QUARTER) {
    os << "en attente d'une piece de 25 cents.";
  } else if (gm.m_state == HAS_QUARTER) {
    os << "en attente d'un tour de manivelle.";
  } else if (gm.m_state == SOLD) {
    os << "en train de livrer une gomme.";
  }
  os << std::endl;
  return os;
}

