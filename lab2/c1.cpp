#include <iostream>
#include <time.h>

using namespace std;

bool find(int no, int arr[], int count) {
  for (int i = 0; i < count; i++) {
    if (no == arr[i]) {
      return true;
    }
  }

  return false;
}

int random(int lower, int upper, int arr[], int count) {
  srand (time(NULL));
  int no = lower;
  do {
    no = (rand() % (upper - lower) + lower);
  } while (find(no, arr, count));
  return no;
}

int main() {
  int arr[10];

  for (int i = 0; i < 10; i++) {
    arr[i] = random(10, 100, arr, i);
  }

  cout << "Numbers: ";

  for (int i = 0; i < 10; i++) {
    cout << arr[i] << "\t";
  }

  return 0;
}
