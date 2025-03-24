#ifndef _MALLARDDUCK_H_
#define _MALLARDDUCK_H_

#include "Duck.h"

class MallardDuck : public Duck {
 public:
  MallardDuck() = default;
  virtual ~MallardDuck() = default;
  virtual void quack();
  virtual void fly();
};

#endif
