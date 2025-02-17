#ifndef MOCHA_H
#define MOCHA_H

#include "CondimentDecorator.h"

class Mocha : public CondimentDecorator {
 public:
  Mocha(Beverage * b);
  std::string getDescription() override;
  double cost() override;
};

#endif
