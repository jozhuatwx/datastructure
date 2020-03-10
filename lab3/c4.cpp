#include <iostream>

using namespace std;

int main() {
  char correct[] = {'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D', 'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A'};
  char ans[20];

  for (int i = 0; i < 20; i++) {
    do {
      cout << "Enter answer for question " << i + 1 << ": ";
      cin >> ans[i];
    } while (ans[i] != 'A' && ans[i] != 'B' && ans[i] != 'C' && ans[i] != 'D');
  };

  int numcorrent = 0;

  for (int i = 0; i < 20; i++) {
    if (ans[i] == correct[i]) {
      numcorrent++;
    };
  };

  if (numcorrent >= 15) {
    cout << "Student has passed the exam.";
  } else {
    cout << "Student has failed the exam.";
  }

  return 0;
};
