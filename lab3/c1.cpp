#include <iostream>
#include <iomanip>

using namespace std;

// function prototype
void convert(double* measurement);

int main() {
  double measurement;

  cout << "Enter a length in inches, and I will convert it to centimeters: ";
  cin >> measurement;

  convert(&measurement);

  cout << fixed << setprecision(4);
  cout << "Value in centimeters: " << measurement << endl;

  return 0;
};

// function convert
void convert(double* measurement) {
  * measurement *= 2.54;
};
