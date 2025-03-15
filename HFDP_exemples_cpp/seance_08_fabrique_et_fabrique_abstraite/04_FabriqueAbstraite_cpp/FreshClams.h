#ifndef _FRESHCLAMS_H_
#define _FRESHCLAMS_H_

#include <string>
#include "Clams.h"

class FreshClams : public Clams {
 public:
  virtual std::string toString() override;
};

#endif
