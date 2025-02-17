#include "Whip.h"

Whip::Whip(Beverage * b) : CondimentDecorator(b) {}

std::string Whip::getDescription()
{
  return getBeverage()->getDescription() + ", Whip";
}

double Whip::cost()
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
