#include "CaffeineBeverage.h"

void CaffeineBeverage::prepareRecipe() {
  boilWater();
  brew();
  pourInCup();
  addCondiments();
}
 
void CaffeineBeverage::boilWater() {
  std::cout << "Boiling water" << std::endl;
}

void CaffeineBeverage::pourInCup() {
  std::cout << "Pouring into cup" << std::endl;
}
