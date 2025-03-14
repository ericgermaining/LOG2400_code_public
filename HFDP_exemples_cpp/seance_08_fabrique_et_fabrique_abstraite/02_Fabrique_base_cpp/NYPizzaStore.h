#ifndef _NYPIZZASTORE_H_
#define _NYPIZZASTORE_H_

#include "PizzaStore.h"
#include "NYStyleCheesePizza.h"
#include "NYStyleVeggiePizza.h"
#include "NYStyleClamPizza.h"
#include "NYStylePepperoniPizza.h"

class NYPizzaStore : public PizzaStore {
 public:
  Pizza * createPizza(std::string item) override;
};

#endif
