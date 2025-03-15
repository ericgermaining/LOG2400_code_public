#ifndef _CHICAGOPIZZASTORE_H_
#define _CHICAGOPIZZASTORE_H_

#include <string>
#include "PizzaStore.h"
#include "PizzaIngredientFactory.h"

class ChicagoPizzaStore : public PizzaStore {
 protected:
  Pizza * createPizza(std::string item);
};

#endif
