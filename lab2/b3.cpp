#include <iostream>

using namespace std;

int main() {
  int no, tempno, digit, rev = 0;

  cout << "Enter a palidrome number: ";
  cin >> no;

  tempno = no;

  do {
    digit = tempno % 10;
    rev = (rev * 10) + digit;
    tempno = tempno / 10;
  } while (tempno != 0);

  cout << no << " is";
  if (rev != no) {
    cout << " not";
  }
  cout << " a palindrome number";

  return 0;
}
