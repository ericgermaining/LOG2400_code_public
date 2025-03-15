#ifndef _CHICAGOPIZZAINGREDIENTFACTORY_H_
#define _CHICAGOPIZZAINGREDIENTFACTORY_H_

#include <vector>
#include "PizzaIngredientFactory.h"
#include "Dough.h"
#include "Sauce.h"
#include "Cheese.h"
#include "Veggies.h"
#include "Pepperoni.h"
#include "Clams.h"

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory 
{
 public:
  Dough * createDough();
  Sauce * createSauce();
  Cheese * createCheese();
  std::vector<Veggies *>  createVeggies();
  Pepperoni * createPepperoni();
  Clams * createClam();
};

#endif
