#ifndef COFFEE_H
#define COFFEE_H

#include "CaffeineBeverage.h"

class Coffee : public CaffeineBeverage {
protected:
  void brew() override;
  void addCondiments() override;
};

#endif
