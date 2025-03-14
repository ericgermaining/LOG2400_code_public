#ifndef _CHICAGOSTYLECHEESEPIZZA_H_
#define _CHICAGOSTYLECHEESEPIZZA_H_

#include "Pizza.h"

class ChicagoStyleCheesePizza : public Pizza {
public:
  ChicagoStyleCheesePizza();
protected:
  virtual void cut() override;
};

#endif
