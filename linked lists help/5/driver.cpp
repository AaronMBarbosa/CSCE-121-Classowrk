#include <iostream>
#include <string>
#include <stdexcept>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::invalid_argument;

int main() {
  LinkedList<int> llInt;
  llInt.insertHead(1);
  llInt.insertHead(9);
  llInt.insertHead(4);
  
  cout << llInt << endl; // print list
  
  try {
    llInt.insertAfter(9, 6); // add 6 after 9
    cout << "Did not throw an exception" << endl;
  }
  catch (invalid_argument& exc) {
    cout << "Exception: " << exc.what() << endl;
  }
  
  cout << llInt << endl; // print list
  
  try {
    llInt.insertAfter(1, 3);  // add 3 after 1 which is a new tail
    cout << "Did not throw an exception" << endl;
  }
  catch (invalid_argument& exc) {
    cout << "Exception: " << exc.what() << endl;
  }
  
  cout << llInt << endl; // pring list
  
  try {
    llInt.insertAfter(7, 11); // should throw an exceptions
    cout << "Did not throw an exception" << endl;
  }
  catch (invalid_argument& exc) {
    cout << "Exception: " << exc.what() << endl;
  }
  
}