#include <iostream>

using namespace std;

struct Point {
  int x, y;
};

int main() {
  // p1 is a pointer to a new Point structure
  Point* p1 = new Point;

  // To access the new structure members using pointer
  p1->x = 3;
  p1->y = 4;

  cout << p1->x << " " << p1->y; // to display

  return 0;
};
