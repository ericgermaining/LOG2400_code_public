#ifndef _TURKEY_H_
#define _TURKEY_H_

class Turkey {
public:
  Turkey() = default;
  virtual ~Turkey() = default;
  virtual void gobble() = 0;
  virtual void fly() = 0;
};

#endif
