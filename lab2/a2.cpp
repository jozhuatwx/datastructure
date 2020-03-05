#include <iostream>

using namespace std;

int add(int a, int b) {
  return a + b;
}

int main() {
  int a, b;
  cout << "Enter two integers: ";
  cin >> a >> b;
  cout << "Sum = " << add(a, b);

  return 0;
}
