#include "SimpleRemoteControl.h"
#include "Light.h"
#include "GarageDoor.h"
#include "LightOnCommand.h"
#include "GarageDoorOpenCommand.h"

int main() {
  SimpleRemoteControl remote;
  
  remote.setCommand(new LightOnCommand(new Light()));
  remote.buttonWasPressed();
  
  remote.setCommand(new GarageDoorOpenCommand(new GarageDoor()));
  remote.buttonWasPressed();
  
}

