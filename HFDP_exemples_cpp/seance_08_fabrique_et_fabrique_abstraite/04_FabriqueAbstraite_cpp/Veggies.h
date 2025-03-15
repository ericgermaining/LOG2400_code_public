#ifndef _VEGGIES_H_
#define _VEGGIES_H_

#include <string>

class Veggies {
 public:
  Veggies() = default;
  virtual ~Veggies() = default;
  virtual std::string toString() = 0;
};

#endif
