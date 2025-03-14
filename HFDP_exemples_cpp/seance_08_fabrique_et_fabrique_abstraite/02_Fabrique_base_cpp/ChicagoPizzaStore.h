#ifndef _CHICAGOPIZZASTORE_H_
#define _CHICAGOPIZZASTORE_H_

#include "PizzaStore.h"
#include "ChicagoStyleCheesePizza.h"
#include "ChicagoStyleVeggiePizza.h"
#include "ChicagoStyleClamPizza.h"
#include "ChicagoStylePepperoniPizza.h"

class ChicagoPizzaStore : public PizzaStore {
 public:
  Pizza * createPizza(std::string item) override;
};

#endif
