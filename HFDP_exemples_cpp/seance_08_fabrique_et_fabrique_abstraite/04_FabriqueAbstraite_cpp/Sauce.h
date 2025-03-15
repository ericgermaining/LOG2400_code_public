#ifndef _SAUCE_H_
#define _SAUCE_H_

#include <string>

class Sauce {
 public:
  Sauce() = default;
  virtual ~Sauce() = default;
  virtual std::string toString() = 0;
};

#endif
