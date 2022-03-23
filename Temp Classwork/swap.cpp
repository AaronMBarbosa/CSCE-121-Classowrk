#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string;

template <typename T> 
void swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

int main() {
  int a = 7, b = 11;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  swap(a, b);
  cout << "after swapping a & b" << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  
  cout << endl;
  
  double c = 12.4, d = 3.92;
  cout << "c: " << c << endl;
  cout << "d: " << d << endl;
  swap(c, d);
  cout << "after swapping c & d" << endl;
  cout << "c: " << c << endl;
  cout << "d: " << d << endl;
  
  cout << endl;
  
  char e = '#', f = 'z';
  cout << "e: " << e << endl;
  cout << "f: " << f << endl;
  swap(e, f);
  cout << "after swapping e & f" << endl;
  cout << "e: " << e << endl;
  cout << "f: " << f << endl;
  
  cout << endl;
  
  string g = "12th", h = "man";
  cout << "g: " << g << endl;
  cout << "h: " << h << endl;
  swap(g, h);
  cout << "after swapping g & h" << endl;
  cout << "g: " << g << endl;
  cout << "h: " << h << endl;
}