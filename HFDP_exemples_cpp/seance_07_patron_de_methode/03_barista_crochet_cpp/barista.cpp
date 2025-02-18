#include "Coffee.h"
#include "Tea.h"

int main()
{
  Tea * tea = new Tea();
  Coffee * coffee = new Coffee();
  
  std::cout << std::endl << "Making tea..." << std::endl;
  tea->prepareRecipe();
  
  std::cout << std::endl << "Making coffee..." << std::endl;
  coffee->prepareRecipe();

  return 0;  
}

