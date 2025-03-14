#ifndef _PIZZA_H_
#define _PIZZA_H_

#include <vector>
#include <string>

class Pizza {
public:
  virtual ~Pizza() = default;
  std::string getName() { return name; }
  std::string toString();
  virtual void prepare();
  virtual void bake();
  virtual void cut();
  virtual void box();

  
protected:
  Pizza() = default;
  std::string name;
  std::string dough;
  std::string sauce;
  std::vector<std::string> toppings;
};

#endif
 
 
