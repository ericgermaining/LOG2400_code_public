#include "Tea.h"

void Tea::brew() {
  std::cout << "Steeping the tea" << std::endl;
}

void Tea::addCondiments() {
  std::cout << "Adding Lemon" << std::endl;
}

bool Tea::customerWantsCondiments() {
  std::string answer = getUserInput();

  if(answer == "y")
    return true;
  else
    return false;
}

std::string Tea::getUserInput() {
  std::string answer;

  std::cout << "Would you like lemon with your tea (y/n)? ";
  std::cin >> answer;
  if(std::cin.fail())
    return "no";
  return answer;
}
