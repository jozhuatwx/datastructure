#include <iostream>

using namespace std;

int main() {
  int no, sum = 0;
  
  do {
    cout << "Please enter a positive integer: ";
    cin >> no;
  } while (no < 0);

  for (int i = 0; i <= no; i++) {
    sum += i;
  }

  cout << "The sum is " << sum;
  
  return 0;
}
