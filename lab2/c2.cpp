#include <iostream>
#include <time.h>

using namespace std;

void generateNumbers(int* arr, int length) {
  for (int i = 0; i < length; i++) {
    arr[i] = (rand() % (50 - 1) + 1);
  }
}

int analyseNumbers(int lower, int upper, int* arr, int* analysed, int count) {
  int no = 0;

  for (int i = 0; i < count; i++) {
    int value = arr[i];
    if (value >= lower && value <= upper) {
      analysed[no] = value;
      no++;
    }
  }
  
  return no;
}

int main() {
  int length;

  cout << "Enter how many numbers you want to do analysis: ";
  cin >> length;

  int* arr = new int[length];
  srand (time(NULL));

  generateNumbers(arr, length);

  cout << "The random numbers (between 1 - 50) as below: " << endl;

  for (int i = 0; i < length; i++) {
    cout << arr[i];
    if ((i + 1) % 10 == 0) {
      cout << endl;
    } else {
      cout << "\t";
    }
  }

  cout << endl << endl;

  cout << "The analysis star design as below: " << endl;
  for (int i = 0; i < 80; i++) {
    cout << "*";
  }

  cout << endl;
  
  int* analysed = new int[length];

  cout << " 1 - 10 | ";
  for (int i = 0; i < analyseNumbers(1, 10, arr, analysed, length); i++) {
    cout << "*" << "\t";
  }

  cout << endl;

  cout << "11 - 20 | ";
  for (int i = 0; i < analyseNumbers(11, 20, arr, analysed, length); i++) {
    cout << "*" << "\t";
  }

  cout << endl;
  
  cout << "21 - 30 | ";
  for (int i = 0; i < analyseNumbers(21, 30, arr, analysed, length); i++) {
    cout << "*" << "\t";
  }

  cout << endl;
  
  cout << "31 - 40 | ";
  for (int i = 0; i < analyseNumbers(31, 40, arr, analysed, length); i++) {
    cout << "*" << "\t";
  }

  cout << endl;

  int verifyNo = analyseNumbers(41, 50, arr, analysed, length);

  cout << "41 - 50 | ";
  for (int i = 0; i < verifyNo; i++) {
    cout << "*" << "\t";
  }

  cout << endl << endl;

  cout << "To verify the graph is correct: (diplay numbers of 41 - 50)" << endl;
  for (int i = 0; i < 80; i++) {
    cout << "*";
  }

  cout << endl;
  for (int i = 0; i < verifyNo; i++) {
    cout << analysed[i];
    if ((i + 1) % 10 == 0) {
      cout << endl;
    } else {
      cout << "\t";
    }
  }
  
  return 0;
}
