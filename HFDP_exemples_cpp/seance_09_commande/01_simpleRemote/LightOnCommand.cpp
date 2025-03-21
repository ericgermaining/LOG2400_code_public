#include "LightOnCommand.h"

LightOnCommand::~LightOnCommand() {
  if(m_light != nullptr)
    delete m_light;
}

void LightOnCommand::execute() {
  if(m_light != nullptr)
    m_light->on();
}

