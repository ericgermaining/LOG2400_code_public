#ifndef _FROZENCLAMS_H_
#define _FROZENCLAMS_H_

#include <string>
#include "Clams.h"

class FrozenClams : public Clams {
 public:
  virtual std::string toString() override;
};

#endif
