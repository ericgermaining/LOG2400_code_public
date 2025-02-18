#ifndef CAFFEINEBEVERAGE_H
#define CAFFEINEBEVERAGE_H

#include <iostream>

class CaffeineBeverage {
 public:
  void prepareRecipe();  
  virtual void brew() = 0;
  virtual void addCondiments() = 0;
  void boilWater();
  void pourInCup();
};

#endif
