#include <iostream>

using namespace std;

int main() {
  int num = 10;
  int* ptr;

  // Stores the address of num to pointer type
  ptr = &num;

  cout << "Address of num = " << &num << endl; // memory address of num
  cout << "Value of num = " << num << endl << endl; // 10

  cout << "Address of ptr = " << &ptr << endl; // memory address of ptr
  cout << "Value of ptr = " << ptr << endl; // memory address of num
  cout << "Value pointed by ptr = " << * ptr << endl; // 10

  return 0;
};
