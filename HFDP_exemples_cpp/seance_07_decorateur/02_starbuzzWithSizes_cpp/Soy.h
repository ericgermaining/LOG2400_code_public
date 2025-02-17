#ifndef SOY_H
#define SOY_H

#include "CondimentDecorator.h"

class Soy : public CondimentDecorator {
 public:
  Soy(Beverage * b);
  std::string getDescription() override;
  double cost() override;
};

#endif
