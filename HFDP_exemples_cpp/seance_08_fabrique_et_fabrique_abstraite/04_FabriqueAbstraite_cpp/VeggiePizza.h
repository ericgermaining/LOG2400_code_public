#include "Pizza.h"
#include "PizzaIngredientFactory.h"
#include <iostream>
class VeggiePizza : public Pizza {
 public:
  VeggiePizza(PizzaIngredientFactory * ingredientFactory);
  virtual ~VeggiePizza();
  virtual void prepare() override;
 private:	  
  PizzaIngredientFactory * m_ingredientFactory;
};
