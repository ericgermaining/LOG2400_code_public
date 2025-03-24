#ifndef _WILDTURKEY_H_
#define _WILDTURKEY_H_

#include "Turkey.h"

class WildTurkey : public Turkey {
 public:
  WildTurkey() = default;
  virtual ~WildTurkey() = default;
  virtual void gobble();  
  virtual void fly();
};

#endif
