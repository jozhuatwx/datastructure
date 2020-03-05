#include <iostream>

using namespace std;

int main() {
  float meal, tip;
  
  do {
    cout << "Input cost of the meal: ";
    cin >> meal;
  } while (meal < 0);

  do {
    cout << "Input tip amount in percentage: ";
    cin >> tip;
  } while (tip < 0 || tip > 100);

  cout << "The total cost of the meal BEFORE GST and tipping: " << meal << endl;
  cout << "The total cost of the meal AFTER GST: " << (meal * 1.06) << endl;
  cout << "The total cost of the meal AFTER GST and tipping: " << (meal * (1.06 + tip/100)) << endl;

  return 0;
}
