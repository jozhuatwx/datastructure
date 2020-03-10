#include <iostream>

using namespace std;

double getLength();
double getWidth();
double getArea(double l, double w);
void displayData(double l, double w, double a);

int main() {
  double l = getLength();
  double w = getWidth();
  double a = getArea(l, w);
  displayData(l, w, a);
};

double getLength() {
  double l;
  cout << "Enter the rectangle's length: ";
  cin >> l;
  return l;
};

double getWidth() {
  double w;
  cout << "Enter the rectangle's width: ";
  cin >> w;
  return w;
};

double getArea(double l, double w) {
  return l * w;
};

void displayData(double l, double w, double a) {
  cout << "The rectangle's length: " << l << endl;
  cout << "The rectangle's width: " << w << endl;
  cout << "The rectangle's area: " << a << endl;
};
