#include <iostream>

using namespace std;

class BankAccount {
  private:
    double balance;
    double interest_rate;

  public:
    // The account balance is set to $dollars.cents
    void set(int dollars, int cents) {
      balance = (double) dollars + (double) cents / 100;
    };

    // One year of simple interest is added to account balance
    void update() {
      balance *= 1 + interest_rate;
    };

    // Return the current account balance
    double get_balance() {
      return balance;
    };

    // Return the current interest rate
    double get_rate() {
      return interest_rate * 100;
    };

    // rate is set to interest rate
    void set_rate(int rate) {
      interest_rate = (double) rate / 100;
    };
} ba;

int main() {
  ba.set(1, 1);
  ba.set_rate(2);
  ba.update();
  cout << "Balance: " << ba.get_balance() << endl;
  cout << "Interest Rate: " << ba.get_rate() << "%";

  return 0;
}
