#include <iostream>

using namespace std;

double calcAverage(int* arr, int size);
int findLowest(int* arr, int size);

int main() {
  int size;

  cout << "Enter the total number of subjects: ";
  cin >> size;

  int* ptr = new int[size];

  for (int i = 0; i < size; i++) {
    do {
      cout << "Enter test score " << i + 1 << ": ";
      cin >> ptr[i];
    } while (ptr[i] <= 0);
  }

  cout << "Average test scores: " << calcAverage(ptr, size) << endl;
  cout << "Lowest test scores: " << findLowest(ptr, size) << endl;

  return 0;
};

double calcAverage(int* arr, int size) {
  int sum = 0;
  
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  return sum / size;
};

int findLowest(int* arr, int size) {
  int min = arr[0];
  for (int i = 1; i < size; i++) {
    if (min > arr[i]) {
      min = arr[i];
    };
  };
  return min;
};
