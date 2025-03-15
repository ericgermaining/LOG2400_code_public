#include <iostream>
#include <sstream>

#include "Pizza.h"

Pizza::~Pizza() {
  if (dough != nullptr)
    delete dough;
  if (sauce != nullptr)
    delete sauce;
  if (cheese != nullptr)
    delete cheese;
  if (!(veggies.empty()))
    for (auto & element : veggies)
      delete element;
  if (clam != nullptr)
    delete clam;
  if (pepperoni != nullptr)
    delete pepperoni;
}

void Pizza::bake() {
  std::cout << "Bake for 25 minutes at 350" << std::endl;
}

void Pizza::cut() {
  std::cout << "Cutting the pizza into diagonal slices" << std::endl;
}

void Pizza::box() {
  std::cout << "Place pizza in official PizzaStore box" << std::endl;
}

std::string Pizza::toString() {
  std::stringstream result;
  result << "---- " <<  m_name << " ----" << std::endl;
  if (dough != nullptr)
    result << dough << std::endl;
  if (sauce != nullptr)
    result << sauce << std::endl;
  if (cheese != nullptr)
    result << cheese << std::endl;
  if (!(veggies.empty())) {
    size_t i = 0;
    for (auto & element : veggies) {
      result << element;
      if (++i < (veggies.size())-1) {
	result << ", ";
      }
    }
    result << "\n";
  }
  if (clam != nullptr)
    result << clam << std::endl;
  if (pepperoni != nullptr)
    result << pepperoni << std::endl;
  return result.str();
}
