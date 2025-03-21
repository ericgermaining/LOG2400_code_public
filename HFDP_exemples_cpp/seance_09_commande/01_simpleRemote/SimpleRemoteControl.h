#ifndef _SIMPLEREMOTECONTROL_H_
#define _SIMPLEREMOTECONTROL_H_

#include "Command.h"

class SimpleRemoteControl {
 private:
  Command * m_slot;
 public:
  SimpleRemoteControl() : m_slot(nullptr) {}
  virtual ~SimpleRemoteControl();
  void setCommand(Command * command);
  void buttonWasPressed();
};

#endif
