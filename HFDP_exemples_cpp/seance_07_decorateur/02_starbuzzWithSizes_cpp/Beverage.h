#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>

class Beverage {
 public:
  Beverage() {}
  Beverage(std::string d) : description(d) {}
  enum Size { TALL, GRANDE, VENTI };                           // AJOUT
  Size size = TALL;                                            // AJOUT
  virtual std::string getDescription() { return description; }
  void setSize(Size size) { this->size = size; }               // AJOUT
  Size getSize() { return this->size; }                        // AJOUT
  virtual double cost() = 0;
 private:
  std::string description;
};

#endif
