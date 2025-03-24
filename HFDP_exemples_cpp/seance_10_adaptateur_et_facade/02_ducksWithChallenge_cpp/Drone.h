#ifndef _DRONE_H_
#define _DRONE_H_

class Drone {
public:
  Drone() = default;
  virtual ~Drone() = default;
  virtual void beep() = 0;
  virtual void spin_rotors() = 0;
  virtual void take_off() = 0;
};

#endif
