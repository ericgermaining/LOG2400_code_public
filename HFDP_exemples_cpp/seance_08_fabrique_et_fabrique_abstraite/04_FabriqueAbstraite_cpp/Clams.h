#ifndef _CLAMS_H_
#define _CLAMS_H_

#include <string>

class Clams {
 public:
  Clams() = default;
  virtual ~Clams() = default;
  virtual std::string toString() = 0;
};

#endif
