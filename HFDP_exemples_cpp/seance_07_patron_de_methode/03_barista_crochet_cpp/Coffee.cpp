#include "Coffee.h"

void Coffee::brew() {
  std::cout << "Dripping Coffee through filter" << std::endl;
}

void Coffee::addCondiments() {
  std::cout << "Adding Sugar and Milk" << std::endl;
}

bool Coffee::customerWantsCondiments() {
  std::string answer = getUserInput();

  if(answer == "y")
    return true;
  else
    return false;
}

std::string Coffee::getUserInput() {
  std::string answer;

  std::cout << "Would you like milk and sugar with your coffee (y/n)? ";
  std::cin >> answer;
  if(std::cin.fail())
    return "no";
  return answer;
}
  

