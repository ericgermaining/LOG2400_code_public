#include "Mocha.h"

Mocha::Mocha(Beverage * b) : CondimentDecorator(b) {}

std::string Mocha::getDescription()
{
  return getBeverage()->getDescription() + ", Mocha";
}

double Mocha::cost()
{
  return .20 + getBeverage()->cost();
}
