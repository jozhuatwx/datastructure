#include <iostream>

using namespace std;

class cashRegister {
  private:
    double cashOnHand;
  public:
    void set(int cash) {
      cashOnHand = cash;
    };

    void acceptAmmount(int ammount) {
      cashOnHand += ammount;
    };

    double printBalance() {
      return cashOnHand;
    };
} cr;

int main() {
  cr.set(500);
  cr.acceptAmmount(250);
  cout << "Balance: " << cr.printBalance();

  return 0;
}
