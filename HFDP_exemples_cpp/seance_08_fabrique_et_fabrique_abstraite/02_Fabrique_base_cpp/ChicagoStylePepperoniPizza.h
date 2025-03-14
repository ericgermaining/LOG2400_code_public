#ifndef _CHICAGOSTYLEPEPPERONIPIZZA_H_
#define _CHICAGOSTYLEPEPPERONIPIZZA_H_

#include "Pizza.h"

class ChicagoStylePepperoniPizza : public Pizza {
public:
  ChicagoStylePepperoniPizza();
protected:
  virtual void cut() override;
};

#endif
