#ifndef _CHEESE_H_
#define _CHEESE_H_

#include <string>

class Cheese {
 public:
  Cheese() = default;
  virtual ~Cheese() = default;
  virtual std::string toString() = 0;
};

#endif
