#include "TurkeyAdapter.h"

void TurkeyAdapter::quack() {
  m_turkey->gobble();
}

void TurkeyAdapter::fly() {
  for(int i=0; i < 5; i++)
    m_turkey->fly();
}
