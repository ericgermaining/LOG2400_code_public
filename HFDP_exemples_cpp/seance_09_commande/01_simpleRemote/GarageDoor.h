#ifndef _GARAGEDOOR_H_
#define _GARAGEDOOR_H_

class GarageDoor {
 public:
  GarageDoor() = default;
  void up();
  void down();
  void stop();
  void lightOn();
  void lightOff();
};

#endif
