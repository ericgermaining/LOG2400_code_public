#include <iostream>

#include "ChicagoStyleCheesePizza.h"

ChicagoStyleCheesePizza::ChicagoStyleCheesePizza() {
  name = "Chicago Style Deep Dish Cheese Pizza";
  dough = "Extra Thick Crust Dough";
  sauce = "Plum Tomato Sauce";
  
  toppings.push_back("Shredded Mozzarella Cheese");
}

void ChicagoStyleCheesePizza::cut() {
  std::cout << "Cutting the pizza into square slices" << std::endl;
}
