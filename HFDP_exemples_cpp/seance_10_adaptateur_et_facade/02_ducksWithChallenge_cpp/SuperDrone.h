#ifndef _SUPERDRONE_H_
#define _SUPERDRONE_H_

#include "Drone.h"

class SuperDrone : public Drone {
 public:
  SuperDrone() = default;
  virtual ~SuperDrone() = default;
  virtual void beep();
  virtual void spin_rotors();
  virtual void take_off();
};

#endif
