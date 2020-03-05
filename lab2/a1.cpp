#include <iostream>

using namespace std;

void add(int a, int b) {
  cout << "Sum = " << a + b;
}

int main() {
  int a, b;
  cout << "Enter two integers: ";
  cin >> a >> b;
  add(a, b);

  return 0;
}
