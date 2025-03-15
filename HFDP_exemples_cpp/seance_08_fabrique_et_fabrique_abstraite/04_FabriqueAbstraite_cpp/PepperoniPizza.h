#include "Pizza.h"
#include "PizzaIngredientFactory.h"
#include <iostream>
class PepperoniPizza : public Pizza {
 public:
  PepperoniPizza(PizzaIngredientFactory * ingredientFactory);
  virtual ~PepperoniPizza();
  virtual void prepare() override;
 private:	  
  PizzaIngredientFactory * m_ingredientFactory;
};
