#include <iostream>

using namespace std;

void bubbleSort(char* arr) {
  bool swap;
  // bubble sort
  for (int i = 1; i < 9; i++) {
    swap = false;
    // last element is in place
    for (int x = 0; x < 8-i; x++) {
      // if value is larger than next value
      if (arr[x] > arr[x+1]) {
        // swap
        char temp = arr[x];
        arr[x] = arr[x+1];
        arr[x+1] = temp;
        swap = true;
      }
    }
    
    // breaks when no elements were swapped (meaning they are sorted)
    if (!swap) {
      break;
    }
  }
}

int main() {
  char arr[8];

  cout << "Enter 8-digit number: ";
  cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6] >> arr[7];

  bubbleSort(arr);

  cout << "Sorted: ";

  for (int i = 0; i < 8; i++) {
    cout << arr[i] << "\t";
  }

  return 0;
}
