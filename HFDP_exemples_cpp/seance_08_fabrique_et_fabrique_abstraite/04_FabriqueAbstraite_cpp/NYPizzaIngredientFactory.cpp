#include "NYPizzaIngredientFactory.h"
#include "ThinCrustDough.h"
#include "MarinaraSauce.h"
#include "ReggianoCheese.h"
#include "Garlic.h"
#include "Onion.h"
#include "Mushroom.h"
#include "RedPepper.h"
#include "SlicedPepperoni.h"
#include "FreshClams.h"

Dough * NYPizzaIngredientFactory::createDough() {
  return new ThinCrustDough();
}
 
Sauce * NYPizzaIngredientFactory::createSauce() {
  return new MarinaraSauce();
}
 
Cheese * NYPizzaIngredientFactory::createCheese() {
  return new ReggianoCheese();
}

std::vector<Veggies *> NYPizzaIngredientFactory::createVeggies() {
  std::vector<Veggies *> veggies;
  veggies.push_back(new Garlic());
  veggies.push_back(new Onion());
  veggies.push_back(new Mushroom());
  veggies.push_back(new RedPepper());
  return veggies;
}
 
Pepperoni * NYPizzaIngredientFactory::createPepperoni() {
  return new SlicedPepperoni();
}

Clams * NYPizzaIngredientFactory::createClam() {
  return new FreshClams();
}

