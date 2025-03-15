#include "VeggiePizza.h"
#include <iostream>

VeggiePizza::VeggiePizza(PizzaIngredientFactory * ingredientFactory)
  : m_ingredientFactory(ingredientFactory) {}

VeggiePizza::~VeggiePizza() {
  if(m_ingredientFactory != nullptr)
    delete m_ingredientFactory;
}

void VeggiePizza::prepare() {
  std::cout << "Preparing " << m_name << std::endl;
  dough = m_ingredientFactory->createDough();
  sauce = m_ingredientFactory->createSauce();
  cheese = m_ingredientFactory->createCheese();
  veggies = m_ingredientFactory->createVeggies();
}
