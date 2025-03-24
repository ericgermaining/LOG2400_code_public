#ifndef _TURKEYADAPTER_H_
#define _TURKEYADAPTER_H_

#include "Duck.h"
#include "Turkey.h"

class TurkeyAdapter : public Duck {
 public:
  TurkeyAdapter(Turkey *turkey) : m_turkey(turkey) {}
  virtual ~TurkeyAdapter() = default;
  
  virtual void quack();
  virtual void fly();

private:
  Turkey * m_turkey;
};

#endif
