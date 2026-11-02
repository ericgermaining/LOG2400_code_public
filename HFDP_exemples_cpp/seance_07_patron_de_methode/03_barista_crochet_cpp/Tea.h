#ifndef TEA_H
#define TEA_H

#include "CaffeineBeverage.h"

class Tea : public CaffeineBeverage {
protected:
  void brew() override;
  void addCondiments() override;
  bool customerWantsCondiments() override;
  
private:
  std::string getUserInput();
  
};

#endif
