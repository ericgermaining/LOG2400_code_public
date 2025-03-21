#ifndef _LIGHTONCOMMAND_H_
#define _LIGHTONCOMMAND_H_

#include "Command.h"
#include "Light.h"

class LightOnCommand : public Command {
public:
  LightOnCommand(Light * light) : m_light(light) {}
  virtual ~LightOnCommand();
  virtual void execute() override;

protected:
  LightOnCommand() = default;

private:
  Light * m_light;

};

#endif
