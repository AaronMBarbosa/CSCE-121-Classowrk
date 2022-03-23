#include <iostream>
#include <string>
#include "LinkedList.h"


int main() {
  LinkedList<int> llInt;

  std::cout<<"before add element:";
  std::cout<<llInt<<std::endl;

  llInt.addHead(5);

  std::cout<<"after adding element:";
  std::cout<<llInt<<std::endl;
}
