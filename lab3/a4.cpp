#include <iostream>

using namespace std;

// function prototype
void swap(int* value1, int* value2);

int main() {
  int num1, num2;

  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  cout << "Before swapping in main function: " << endl;
  cout << "Value of num1 = " << num1 << endl;
  cout << "Value of num2 = " << num2 << endl << endl;

  swap(&num1, &num2);
  
  cout << "After swapping in main function: " << endl;
  cout << "Value of num1 = " << num1 << endl;
  cout << "Value of num2 = " << num2 << endl << endl;

  return 0;
};

void swap(int* value1, int* value2) {
  int temp = * value1;
  * value1 = * value2;
  * value2 = temp;
  
  cout << "After swapping in swap function: " << endl;
  cout << "Value of num1 = " << * value1 << endl;
  cout << "Value of num2 = " << * value2 << endl << endl;
};
