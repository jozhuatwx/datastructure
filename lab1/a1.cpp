// import library
#include <iostream>

// using namespace std
using namespace std;

int main() {
  // initialize variable
  /* string sentence;
  int age;

  cout << "Enter your age: ";
  cin >> age;
  cin.ignore(); // refresh buffer
  age = age * 2;

  if (age > 2 && age < 0) {
    cout << "Not allow to enter";
  }

  cout << "Enter a sentence: ";
  // cin >> sentence;
  getline(cin, sentence);

  cout << "The Sentence is: " << sentence;

  return 0; */

  int hours, minutes, seconds;
  char separator;

  cout << "Please enter your elapsed time (in HH:MM:SS format) = ";
  cin >> hours >> separator >> minutes >> separator >> seconds;

  int elapsedTime = (hours * 60 * 60) + (minutes * 60) + seconds;
  cout << "Elapsed time is: " << elapsedTime << " seconds." << endl;
  return 0;
}