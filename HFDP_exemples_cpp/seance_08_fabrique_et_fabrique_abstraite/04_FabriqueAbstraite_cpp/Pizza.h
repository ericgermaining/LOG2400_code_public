#ifndef _PIZZA_H_
#define _PIZZA_H_

#include <string>
#include <vector>
#include "Dough.h"
#include "Sauce.h"
#include "Veggies.h"
#include "Cheese.h"
#include "Pepperoni.h"
#include "Clams.h"

class Pizza {
public:
  Pizza() = default;
  virtual ~Pizza();
  virtual void prepare() = 0;
  void bake();
  void cut();
  void box();
  void setName(std::string name) { m_name = name; }
  std::string getName() { return m_name; }
  std::string toString();

protected:
  std::string m_name;
  Dough * dough;
  Sauce * sauce;
  std::vector<Veggies *> veggies;
  Cheese * cheese;
  Pepperoni * pepperoni;
  Clams * clam;
};

#endif
