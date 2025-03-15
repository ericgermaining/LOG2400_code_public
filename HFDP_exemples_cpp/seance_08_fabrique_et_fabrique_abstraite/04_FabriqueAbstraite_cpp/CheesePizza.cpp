#include "CheesePizza.h"
#include <iostream>

CheesePizza::CheesePizza(PizzaIngredientFactory * ingredientFactory)
  : m_ingredientFactory(ingredientFactory) {}

CheesePizza::~CheesePizza() {
  if(m_ingredientFactory != nullptr)
    delete m_ingredientFactory;
}

void CheesePizza::prepare() {
  std::cout << "Preparing " << m_name << std::endl;
  dough = m_ingredientFactory->createDough();
  sauce = m_ingredientFactory->createSauce();
  cheese = m_ingredientFactory->createCheese();
}

