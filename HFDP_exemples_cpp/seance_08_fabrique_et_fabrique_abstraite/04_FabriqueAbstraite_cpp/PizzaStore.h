#ifndef _PIZZASTORE_H_
#define _PIZZASTORE_H_

#include <string>
#include <iostream>
#include "Pizza.h"

class PizzaStore {
 public:
  PizzaStore() = default;
  virtual ~PizzaStore() = default;
  Pizza * orderPizza(std::string type);

 protected:
  virtual Pizza * createPizza(std::string item) = 0;
};

#endif
