#ifndef _COMMAND_H_
#define _COMMAND_H_

class Command {
 public:
  virtual ~Command() = default;
  virtual void execute() = 0;
};

#endif
