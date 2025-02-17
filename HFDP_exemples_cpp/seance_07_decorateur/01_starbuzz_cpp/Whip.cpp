#include "Whip.h"

Whip::Whip(Beverage * b) : CondimentDecorator(b) {}

std::string Whip::getDescription()
{
  return getBeverage()->getDescription() + ", Whip";
}

double Whip::cost()
{
  return .10 + getBeverage()->cost();
}
