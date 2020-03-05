#include <iostream>

using namespace std;

void getEven(int a, int b, int* arr, int* size) {
  if (a > b) {
    int temp = a;
    a = b;
    b = a;
  }
  
  *size = (b - a)/2;

  if (a % 2 == 0) {
    *size += 1;
  }
  
  if (a%2 != 0 && a != b) {
    a++;
  }

  for (int i = 0; a <= b; a += 2, i++) {
    arr[i] = a;
  }
}

int main() {
  int a, b;
  int* size;

  cout << "Enter two integers: ";
  cin >> a >> b;

  int* arr = new int[*size];
  getEven(a, b, arr, size);

  for (int i = 0; i < *size; i++) {
    cout << arr[i] << "\t";
  }

  delete [] arr;
  
  return 0;
}
