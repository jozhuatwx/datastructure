#include <iostream>
#include <string>

using namespace std;

int main() {
  // Simple declarations
  string word = "abc";
  int integer = 1;
  float real = 10.4f;
  long long biginteger = 98989898911;

  // Print variable value with their memory address
  cout << "Value of character = " << word << ", Address of character = " << &word << endl;
  cout << "Value of character = " << integer << ", Address of character = " << &integer << endl;
  cout << "Value of character = " << real << ", Address of character = " << &real << endl;
  cout << "Value of character = " << biginteger << ", Address of character = " << &biginteger << endl;

  return 0;
};
