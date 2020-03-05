#include <iostream>

using namespace std;

int main() {
  for (int i = 1; i <= 50; i++) {
    if (i % 2 == 0) {
      cout << i << " ";
      if (i % 5 == 0) {
        cout << endl;
      }
    }
  }

  return 0;
}
