#ifndef MILK_H
#define MILK_H

#include "CondimentDecorator.h"

class Milk : public CondimentDecorator {
 public:
  Milk(Beverage * b);
  std::string getDescription() override;
  double cost() override;
};

#endif
