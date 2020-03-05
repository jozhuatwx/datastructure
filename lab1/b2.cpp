#include <iostream>

using namespace std;

int main() {
  int no;
  string num;

  do {
    cout << "Enter a number within 1 to 10: ";
    cin >> no;
  } while (no < 1 || no > 10);

  switch (no) {
    case 1:
      num = "I";
      break;

    case 2:
      num = "II";
      break;

    case 3:
      num = "III";
      break;

    case 4:
      num = "IV";
      break;

    case 5:
      num = "V";
      break;

    case 6:
      num = "VI";
      break;

    case 7:
      num = "VII";
      break;

    case 8:
      num = "VII";
      break;

    case 9:
      num = "IX";
      break;

    case 10:
      num = "X";
      break;
  }

  cout << "Roman numeral: " << num;

  return 0;
}
