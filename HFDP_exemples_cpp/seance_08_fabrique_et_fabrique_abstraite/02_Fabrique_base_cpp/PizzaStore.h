#ifndef _PIZZASTORE_H_
#define _PIZZASTORE_H_

#include "Pizza.h"

class PizzaStore {
 public:
  PizzaStore() = default;
  virtual ~PizzaStore() = default;
  virtual Pizza * createPizza(std::string item) = 0;
  Pizza * orderPizza(std::string type);
};

#endif
