#include "Soy.h"

Soy::Soy(Beverage * b) : CondimentDecorator(b) {}

std::string Soy::getDescription()
{
  return getBeverage()->getDescription() + ", Soy";
}

double Soy::cost()
{
  double cost = getBeverage()->cost();
  if(getBeverage()->getSize() == TALL)
    cost += .10;
  else if(getBeverage()->getSize() == GRANDE)
    cost += .15;
  else if(getBeverage()->getSize() == VENTI)
    cost += .20;
  return cost;
}
