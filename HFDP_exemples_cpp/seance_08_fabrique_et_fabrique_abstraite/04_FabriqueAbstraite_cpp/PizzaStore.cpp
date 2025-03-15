#include "PizzaStore.h"

Pizza * PizzaStore::orderPizza(std::string type) {
  Pizza * pizza = createPizza(type);
  std::cout << "--- Making a " << pizza->getName() << " ---";
  pizza->prepare();
  pizza->bake();
  pizza->cut();
  pizza->box();
  return pizza;
}

