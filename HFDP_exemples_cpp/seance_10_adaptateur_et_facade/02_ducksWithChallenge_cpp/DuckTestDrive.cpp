#include <iostream>

#include "MallardDuck.h"
#include "WildTurkey.h"
#include "TurkeyAdapter.h"
#include "SuperDrone.h"
#include "DroneAdapter.h"

static void testDuck(Duck * duck) {
  duck->quack();
  duck->fly();
}

int main()
{
  Duck * duck = new MallardDuck();
  Turkey * turkey = new WildTurkey();
  Duck * turkeyAdapter = new TurkeyAdapter(turkey);
  
  std::cout << "The Turkey says..." << std::endl;
  turkey->gobble();
  turkey->fly();
  
  std::cout << "\nThe Duck says..." << std::endl;
  testDuck(duck);
  
  std::cout << std::endl << "The TurkeyAdapter says..." << std::endl;
  testDuck(turkeyAdapter);

  // Challenge
  Drone * drone = new SuperDrone();
  Duck * droneAdapter = new DroneAdapter(drone);
  testDuck(droneAdapter);
  delete droneAdapter;
  delete drone;
  // fin Challenge
  
  delete turkeyAdapter;
  delete turkey;
  delete duck;
  
  return 0;
}


