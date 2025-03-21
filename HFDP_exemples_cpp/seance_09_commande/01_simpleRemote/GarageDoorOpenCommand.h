#ifndef _GARAGEDOOROPENCOMMAND_H_
#define _GARAGEDOOROPENCOMMAND_H_

#include "Command.h"
#include "GarageDoor.h"

class GarageDoorOpenCommand : public Command {
 public:
 GarageDoorOpenCommand(GarageDoor * garageDoor)
   : m_garageDoor(garageDoor) {}
  virtual ~GarageDoorOpenCommand();

  virtual void execute() override;

protected:
  GarageDoorOpenCommand() = default;

private:
  GarageDoor * m_garageDoor;


};

#endif
