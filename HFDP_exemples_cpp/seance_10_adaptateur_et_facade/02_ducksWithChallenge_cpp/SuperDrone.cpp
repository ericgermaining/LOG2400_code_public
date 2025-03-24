#include <iostream>
#include "SuperDrone.h"

void SuperDrone::beep() {
  std::cout << "Beep beep beep" << std::endl;
}

void SuperDrone::spin_rotors() {
  std::cout << "Rotors are spinning" << std::endl;
}

void SuperDrone::take_off() {
  std::cout << "Taking off" << std::endl;
}
