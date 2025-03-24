#include <ctime>
#include <stdlib.h>
#include "DuckAdapter.h"

void DuckAdapter::gobble() {
  m_duck->quack();
}
  
void DuckAdapter::fly() {
  srand(time(0));
  if ((rand() % 5) == 0)
    m_duck->fly();
}
