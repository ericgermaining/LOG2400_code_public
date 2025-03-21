#include "SimpleRemoteControl.h"

SimpleRemoteControl::~SimpleRemoteControl() {
  if(m_slot != nullptr)
    delete m_slot;
}

void SimpleRemoteControl::setCommand(Command * command) {
  if(m_slot != nullptr)
    delete m_slot;
  m_slot = command;
}
 
void SimpleRemoteControl::buttonWasPressed() {
  if(m_slot != nullptr)
    m_slot->execute();
}

