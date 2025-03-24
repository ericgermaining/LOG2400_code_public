#include "DroneAdapter.h"

void DroneAdapter::quack() {
  m_drone->beep();
}
  
void DroneAdapter::fly() {
  m_drone->spin_rotors();
  m_drone->take_off();
}
