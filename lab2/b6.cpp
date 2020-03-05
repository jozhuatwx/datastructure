#include <iostream>

using namespace std;

int main() {
  int row, col;

  cout << "Enter the number of rows and columns of matrix: ";
  cin >> row >> col;

  int arr[2][col][row];

  cout << "Enter the elements of the first matrix: " << endl;
  for (int i = 0; i < col; i++) {
    for (int x = 0; x < row; x++) {
      cin >> arr[0][i][x];
    }
  }

  cout << "Enter the elements of the second matrix: " << endl;
  for (int i = 0; i < col; i++) {
    for (int x = 0; x < row; x++) {
      cin >> arr[1][i][x];
    }
  }

  cout << "Sum of the entered matrices: " << endl;

  for (int i = 0; i < col; i++) {
    for (int x = 0; x < row; x++) {
      cout << arr[0][i][x] + arr[1][i][x] << "\t";
    }
    cout << endl;
  }

  return 0;
}
