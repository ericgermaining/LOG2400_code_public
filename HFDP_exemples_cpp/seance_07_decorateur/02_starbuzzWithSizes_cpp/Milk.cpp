#include "Milk.h"

Milk::Milk(Beverage * b) : CondimentDecorator(b) {}

std::string Milk::getDescription()
{
  return getBeverage()->getDescription() + ", Milk";
}

double Milk::cost()
{
  double cost = getBeverage()->cost();
  if(getBeverage()->getSize() == TALL)
    cost += .05;
  else if(getBeverage()->getSize() == GRANDE)
    cost += .10;
  else if(getBeverage()->getSize() == VENTI)
    cost += .15;
  return cost;
}
