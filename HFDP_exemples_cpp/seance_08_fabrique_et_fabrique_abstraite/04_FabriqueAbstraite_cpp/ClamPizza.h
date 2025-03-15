#include "Pizza.h"
#include "PizzaIngredientFactory.h"
#include <iostream>

class ClamPizza : public Pizza {
 public:
  ClamPizza(PizzaIngredientFactory * ingredientFactory);
  virtual ~ClamPizza();
  virtual void prepare() override;
 private:	  
  PizzaIngredientFactory * m_ingredientFactory;
};
