#include <iostream>

using namespace std;

int main() {
  int no1, no2;

  cout << "Enter two integers: ";
  cin >> no1 >> no2;

  if (no1 % no2 == 0) {
    cout << no1 << " is a multiple of " << no2;
  } else {
    cout << no1 << " is not a multiple of " << no2;
  }

  return 0;
}
