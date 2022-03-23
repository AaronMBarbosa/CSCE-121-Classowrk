#include <iostream>
#include <string>
#include "LinkedList.h"


int main() {
  LinkedList<int> llInt;
  std::cout<<"output from the print:";
  llInt.print();
  std::cout<<std::endl;
  std::cout<<"output from output operator:";
  std::cout<<llInt<<std::endl;
}
