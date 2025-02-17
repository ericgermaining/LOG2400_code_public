#include "Mocha.h"

Mocha::Mocha(Beverage * b) : CondimentDecorator(b) {}

std::string Mocha::getDescription()
{
  return getBeverage()->getDescription() + ", Mocha";
}

double Mocha::cost()
{
  double cost = getBeverage()->cost();
  if(getBeverage()->getSize() == TALL)
    cost += .15;
  else if(getBeverage()->getSize() == GRANDE)
    cost += .20;
  else if(getBeverage()->getSize() == VENTI)
    cost += .25;
  return cost;
}
