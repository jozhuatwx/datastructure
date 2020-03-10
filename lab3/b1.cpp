#include <iostream>

using namespace std;

int main() {
  int size;

  cout << "Enter the size of array: ";
  cin >> size;

  int* ptr = new int[size];

  cout << "Now, build an array with 4 columns." << endl;
  cout << "Enter elements in the developed array: " << endl;

  for (int i = 0; i < size; i++) {
    cin >> ptr[i];
  }

  cout << "The array elements = ";
  for (int i = 0; i < size; i++) {
    cout << ptr[i] << ", ";
  }

  return 0;
};
