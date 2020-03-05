#include <iostream>

using namespace std;

int main() {
  int length, sum = 0;
  
  cout << "Enter the length of array: ";
  cin >> length;

  int array[length];

  for (int i = 0; i < length; i++) {
    cout << "Enter your number " << (i + 1) << ": ";
    cin >> array[i];
  }

  for (int i = 0; i < length; i++) {
    sum += array[i];
  }

  cout << "Sum = " << sum;

  return 0;
}
