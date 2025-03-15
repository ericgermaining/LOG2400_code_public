#ifndef _NYPIZZASTORE_H_
#define _NYPIZZASTORE_H_

#include <string>
#include "PizzaStore.h"
#include "PizzaIngredientFactory.h"

class NYPizzaStore : public PizzaStore {
 protected:
  Pizza * createPizza(std::string item);
};

#endif
