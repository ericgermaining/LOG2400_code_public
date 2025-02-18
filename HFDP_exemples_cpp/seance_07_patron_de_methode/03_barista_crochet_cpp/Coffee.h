#ifndef COFFEE_H
#define COFFEE_H

#include "CaffeineBeverage.h"

class Coffee : public CaffeineBeverage {
public:
  void brew() override;
  void addCondiments() override;
  bool customerWantsCondiments() override;
  
private:
  std::string getUserInput();
};

#endif
