#include <iostream>

using namespace std;

int main() {
  int array[5], sum = 0;

  for (int i = 0; i < 5; i++) {
    cout << "Enter your number " << (i + 1) << ":";
    cin >> array[i];
  }

  for (int i = 0; i < 5; i++) {
    cout << array[i] << " ";
    switch (i) {
      case 4:
        cout << "= ";
        break;
      
      default:
        cout << "+ ";
        break;
    }
    sum += array[i];
  }

  cout << sum;

  return 0;
}
