#include <iostream>
#include <string>
#include "LinkedList.h"

using std::cout;
using std::endl;

int main() {
  LinkedList<int> llInt;
  llInt.insertHead(1);
  llInt.insertHead(9);
  llInt.insertHead(4);
  
  cout << llInt << endl; // print list
  
  cout << "9 is";
  if (!llInt.hasValue(9)) {
    cout << " not";
  }
  cout << " in the list" << endl;
  
  cout << "3 is";
  if (!llInt.hasValue(3)) {
    cout << " not";
  }
  cout << " in the list" << endl;
 }