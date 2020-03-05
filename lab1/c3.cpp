#include <iostream>

using namespace std;

int main() {
  float cal = 0;
  
  for (int i = 1; i <= 30; i++) {
    cal = i * 3.9;

    switch (i) {
      case 10:
        cout << "10 minutes: " << cal << " calories" << endl;
        break;

      case 15:
        cout << "15 minutes: " << cal << " calories" << endl;
        break;

      case 20:
        cout << "20 minutes: " << cal << " calories" << endl;
        break;

      case 25:
        cout << "25 minutes: " << cal << " calories" << endl;
        break;

      case 30:
        cout << "30 minutes: " << cal << " calories" << endl;
        break;
      
      default:
        break;
    }
  }
  return 0;
}