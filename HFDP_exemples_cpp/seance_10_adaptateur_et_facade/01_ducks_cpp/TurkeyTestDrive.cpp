#include <iostream>

#include "MallardDuck.h"
#include "DuckAdapter.h"

int main()
{
  MallardDuck * duck = new MallardDuck();
  Turkey * duckAdapter = new DuckAdapter(duck);
  
  for(int i=0;i<10;i++) {
    std::cout << "The DuckAdapter says..." << std::endl;
    duckAdapter->gobble();
    duckAdapter->fly();
  }

  delete duckAdapter;
  delete duck;
  
  return 0;
}

