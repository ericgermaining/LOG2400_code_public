#ifndef CONDIMENTDECORATOR_H
#define CONDIMENTDECORATOR_H

#include "Beverage.h"

class CondimentDecorator : public Beverage {
 public:
  CondimentDecorator(Beverage * b) : beverage(b) {}
  Beverage * getBeverage() { return beverage; }
  std::string getDescription() override = 0;
 private:
  Beverage * beverage;
};

#endif
