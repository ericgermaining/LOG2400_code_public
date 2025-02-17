#include "Soy.h"

Soy::Soy(Beverage * b) : CondimentDecorator(b) {}

std::string Soy::getDescription()
{
  return getBeverage()->getDescription() + ", Soy";
}

double Soy::cost()
{
  return .15 + getBeverage()->cost();
}
