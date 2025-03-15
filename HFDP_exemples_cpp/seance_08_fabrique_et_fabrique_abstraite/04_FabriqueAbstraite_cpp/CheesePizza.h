#include "Pizza.h"
#include "PizzaIngredientFactory.h"
#include <iostream>
class CheesePizza : public Pizza {
 public:
  CheesePizza(PizzaIngredientFactory * ingredientFactory);
  virtual ~CheesePizza();
  virtual void prepare() override;
 private:	  
  PizzaIngredientFactory * m_ingredientFactory;
};
