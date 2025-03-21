#ifndef _LIGHTOFFCOMMAND_H_
#define _LIGHTOFFCOMMAND_H_

#include "Command.h"
#include "Light.h"

class LightOffCommand : public Command {
public:
  LightOffCommand(Light * light) : m_light(light) {}
  virtual ~LightOffCommand();
  virtual void execute() override;
  
protected:
  LightOffCommand() = default;
  
private:
  Light * m_light;
};

#endif
