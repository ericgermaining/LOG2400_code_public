#ifndef _CHICAGOSTYLECLAMPIZZA_H_
#define _CHICAGOSTYLECLAMPIZZA_H_

#include "Pizza.h"

class ChicagoStyleClamPizza : public Pizza {
public:
  ChicagoStyleClamPizza();
protected:
  virtual void cut() override;
};

#endif
