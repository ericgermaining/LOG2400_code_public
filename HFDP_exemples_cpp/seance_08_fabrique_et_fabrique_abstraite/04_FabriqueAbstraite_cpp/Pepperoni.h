#ifndef _PEPPERONI_H_
#define _PEPPERONI_H_

#include <string>

class Pepperoni {
 public:
  Pepperoni() = default;
  virtual ~Pepperoni() = default;
  virtual std::string toString() = 0;
};

#endif
