#include <iostream>
#include <sstream>
#include "Pizza.h"

void Pizza::prepare() {
  std::cout << "Prepare " << name << std::endl;
  std::cout << "Tossing dough..." << std::endl;
  std::cout << "Adding sauce..." << std::endl;
  std::cout << "Adding toppings: " << std::endl;
  for (auto topping : toppings)
    std::cout << "   " + topping << std::endl;
}

void Pizza::bake() {
  std::cout << "Bake for 25 minutes at 350" << std::endl;
}

void Pizza::cut() {
  std::cout << "Cut the pizza into diagonal slices" << std::endl;
}

void Pizza::box() {
  std::cout << "Place pizza in official PizzaStore box" << std::endl;
}

std::string Pizza::toString() {
  std::stringstream display;
  display << "---- " << name << " ----" << std::endl;
  display << dough << std::endl;
  display << sauce << std::endl;
  for (auto topping : toppings) {
    display << topping << std::endl;
  }
  return display.str();
}

 
 
