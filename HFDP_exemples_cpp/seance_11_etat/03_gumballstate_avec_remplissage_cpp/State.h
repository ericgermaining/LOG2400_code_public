#ifndef _STATE_H_
#define _STATE_H_

class State {
 public:
  State() = default;
  virtual ~State() = default;
  virtual void insertQuarter() = 0;
  virtual void ejectQuarter() = 0;
  virtual void turnCrank() = 0;
  virtual void dispense() = 0;
  virtual void refill() = 0;
  friend std::ostream & operator<<(std::ostream& os, State& state) { return state.stateToStream(os); }

private:
  virtual std::ostream & stateToStream(std::ostream& os) = 0;
};

#endif
