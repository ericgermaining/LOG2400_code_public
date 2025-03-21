#include "LightOffCommand.h"

LightOffCommand::~LightOffCommand() {
  if(m_light != nullptr)
    delete m_light;
}

void LightOffCommand::execute() {
  if(m_light != nullptr)
    m_light->off();
}

