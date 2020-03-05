#include <iostream>

using namespace std;

int calc(int hours, int minutes, int seconds) {
  int elapsedTime = (hours * 60 * 60) + (minutes * 60) + seconds;
  return elapsedTime;
}

int main() {
  int hours, minutes, seconds;
  char separator;

  cout << "Please enter your elapsed time (in HH:MM:SS format) = ";
  cin >> hours >> separator >> minutes >> separator >> seconds;

  cout << "Elapsed time is: " << calc(hours, minutes, seconds) << " seconds" << endl;
  
  return 0;
}
