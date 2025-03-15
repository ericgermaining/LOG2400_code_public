#include <iostream>
#include "ClamPizza.h"

ClamPizza::ClamPizza(PizzaIngredientFactory * ingredientFactory)
  : m_ingredientFactory(ingredientFactory) {}

ClamPizza::~ClamPizza() {
  if(m_ingredientFactory != nullptr)
    delete m_ingredientFactory;
}


void ClamPizza::prepare() {
  std::cout << "Preparing " << m_name << std::endl;
  dough = m_ingredientFactory->createDough();
  sauce = m_ingredientFactory->createSauce();
  cheese = m_ingredientFactory->createCheese();
  clam = m_ingredientFactory->createClam();
}
