#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>

class Beverage {
 public:
  Beverage() {}
  Beverage(std::string d) : description(d) {}
  virtual std::string getDescription() { return description; }
  virtual double cost() = 0;
 private:
  std::string description;
};

#endif
