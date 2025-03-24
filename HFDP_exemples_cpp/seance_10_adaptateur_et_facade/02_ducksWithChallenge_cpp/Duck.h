#ifndef _DUCK_H_
#define _DUCK_H_

class Duck {
 public:
  Duck() = default;
  virtual ~Duck() = default;
  virtual void quack() = 0;
  virtual void fly() = 0;
};

#endif
