#include <iostream>

using namespace std;

int main() {
  string month;
  int days = 0, year = 0, hot = 0, rainy = 0, cloudy = 0;
  char input;

  do {
    cout << "Enter your month (e.g. August 2019): ";
    cin >> month >> year;
  } while (month == "" || year < 1);

  if (month == "January" || month == "March" || month == "May" || month == "July" || month == "August" || month == "October" || month == "December") {
    days = 31;
  } else if (month == "February") {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
      days = 29;
    } else {
      days = 28;
    }
  } else if (month == "April" || month == "June" || month == "September" || month == "November") {
    days = 30;
  }

  for (int i = 0; i < days; i++) {
    do {
      cout << "Day " << i + 1 << ": Enter \"H\" for Hot, \"R\" for Rainy, \"C\" for Cloudy, (\"E\" to end): ";
      cin >> input;
    } while (input != 'h' && input != 'H' && input != 'r' && input != 'R' && input != 'c' && input != 'C' && input != 'e' && input != 'E');

    switch (input) {
      case 'h':
      case 'H':
        hot += 1;
        break;

      case 'r':
      case 'R':
        rainy += 1;
        break;

      case 'c':
      case 'C':
        cloudy += 1;
        break;
      
      default:
        return 0;
        break;
    }
  }
  
  cout << "Number of hot days this month: " << hot << endl << "Number of rainy days this month: " << rainy << endl << "Number of cloudy days this month: " << cloudy;

  return 0;
}
