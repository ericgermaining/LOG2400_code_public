#include "GarageDoorOpenCommand.h"

GarageDoorOpenCommand::~GarageDoorOpenCommand() {
  if(m_garageDoor != nullptr)
    delete m_garageDoor;
}

void GarageDoorOpenCommand::execute() {
  if(m_garageDoor != nullptr)
    m_garageDoor->up();
}
