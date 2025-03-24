#ifndef _DUCKADAPTER_H_
#define _DUCKADAPTER_H_

#include "Turkey.h"
#include "Duck.h"

class DuckAdapter : public Turkey {
 public:  
  DuckAdapter(Duck * duck) : m_duck(duck) {};
  virtual ~DuckAdapter() = default;
  virtual void gobble();
  virtual void fly();

 private:
  Duck * m_duck;
};

#endif
