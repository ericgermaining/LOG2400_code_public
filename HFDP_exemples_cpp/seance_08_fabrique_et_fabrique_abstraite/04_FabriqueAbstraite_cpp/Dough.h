#ifndef _DOUGH_H_
#define _DOUGH_H_

#include <string>

class Dough {
 public:
  Dough() = default;
  virtual ~Dough() = default;
  virtual std::string toString() = 0;
};

#endif
