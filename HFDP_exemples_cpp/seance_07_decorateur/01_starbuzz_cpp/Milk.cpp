#include "Milk.h"

Milk::Milk(Beverage * b) : CondimentDecorator(b) {}

std::string Milk::getDescription()
{
  return getBeverage()->getDescription() + ", Milk";
}

double Milk::cost()
{
  return .10 + getBeverage()->cost();
}
