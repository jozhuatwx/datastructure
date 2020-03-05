#include <iostream>

using namespace std;

int main() {
  int rows, asterisk;

  cout << "Enter number of rows (for diamond (triangle) dimension): ";
  cin >> rows;

  int x = 0, y = 0;

  int total = (2 * rows - 1);

  for (int i = 0; i < total; i++) {
    // Print first half
    if (i < rows) {
      // Print spacing
      for (x = 0; x < (rows - i - 1); x++) {
        cout << " ";
      }

      // Print asterik
      for (y = 0; y < (1 + (2 * i)); y++) {
        cout << "*";
      }
    // Print second half
    } else {
      // Print spacing
      for (x = 0; x < ((i + 1) - rows); x++) {
        cout << " ";
      }

      // Print asterik
      for (y = 0; y < (1 + (2 * (total - (i + 1)))); y++) {
        cout << "*";
      }
    }

    // Break lines
    cout << endl;
  }

  return 0;
}
