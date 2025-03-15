#include "PepperoniPizza.h"
#include <iostream>

PepperoniPizza::PepperoniPizza(PizzaIngredientFactory * ingredientFactory)
  : m_ingredientFactory(ingredientFactory) {}

PepperoniPizza::~PepperoniPizza() {
  if(m_ingredientFactory != nullptr)
    delete m_ingredientFactory;
}

void PepperoniPizza::prepare() {
  std::cout << "Preparing " << m_name << std::endl;
  dough = m_ingredientFactory->createDough();
  sauce = m_ingredientFactory->createSauce();
  cheese = m_ingredientFactory->createCheese();
  veggies = m_ingredientFactory->createVeggies();
  pepperoni = m_ingredientFactory->createPepperoni();
}

