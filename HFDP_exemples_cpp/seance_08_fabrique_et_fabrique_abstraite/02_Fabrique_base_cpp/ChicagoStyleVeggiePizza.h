#ifndef _CHICAGOSTYLEVEGGIEPIZZA_H_
#define _CHICAGOSTYLEVEGGIEPIZZA_H_

#include "Pizza.h"

class ChicagoStyleVeggiePizza : public Pizza {
public:
  ChicagoStyleVeggiePizza();
protected:
  virtual void cut() override;
};

#endif
