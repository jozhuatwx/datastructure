#include <iostream>

using namespace std;

int main() {
  int quiz, mid, final;
  float avg;

  cout << "Enter 3 scores (quiz, mid-term, and final) values separated by spaces: ";
  cin >> quiz >> mid >> final;

  avg = (quiz + mid + final) / 3;
  
  if (avg >= 90) {
    cout << "Grade A";
  } else if (avg >= 70) {
    cout << "Grade B";
  } else if (avg >= 50) {
    cout << "Grade C";
  } else {
    cout << "Grade F";
  }

  return 0;
}
