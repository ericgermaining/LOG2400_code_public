#ifndef _PIZZAINGREDIENTFACTORY_H_
#define _PIZZAINGREDIENTFACTORY_H_

#include <vector>
#include "Dough.h"
#include "Sauce.h"
#include "Cheese.h"
#include "Veggies.h"
#include "Pepperoni.h"
#include "Clams.h"

class PizzaIngredientFactory {
public:
  PizzaIngredientFactory() = default;
  virtual ~PizzaIngredientFactory() = default;
  virtual Dough * createDough() = 0;
  virtual Sauce * createSauce() = 0;
  virtual Cheese * createCheese() = 0;
  virtual std::vector<Veggies *> createVeggies() = 0;
  virtual Pepperoni * createPepperoni() = 0;
  virtual Clams * createClam() = 0;
};

#endif
