#ifndef _DRONEADAPTER_H_
#define _DRONEADAPTER_H_

#include "Duck.h"
#include "Drone.h"

class DroneAdapter : public Duck {
 public:
  DroneAdapter(Drone * drone) : m_drone(drone) {}
  virtual ~DroneAdapter() = default;
  virtual void quack();
  virtual void fly();
  
 private:
  Drone * m_drone;
};

#endif
