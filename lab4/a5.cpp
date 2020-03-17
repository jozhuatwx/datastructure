#include <iostream>

using namespace std;

class cashRegister {
  private:
    int cashOnHand;
  
  public:
    cashRegister(int cash) {
      cashOnHand = cash;
    };

    cashRegister() {
      cashRegister(500);
    };

    int getCurrentBalance() {
      return cashOnHand;
    };

    void acceptAmmount(int ammount) {
      cashOnHand += ammount;
    };
};

class dispenserType {
  private:
    int numberOfItems;
    int cost;
  
  public:
    dispenserType(int items, int cos) {
      numberOfItems = items;
      cost = cos;
    };

    dispenserType() {
      dispenserType(50, 50);
    };

    int getNoOfItems() {
      return numberOfItems;
    };

    int getCost() {
      return cost;
    };

    void makeSale() {
      numberOfItems -= 1;
    };
};

int main() {
  int selected;
  char agree;

  cashRegister cr(500);
  dispenserType apple(1, 50);
  dispenserType orange(0, 40);
  dispenserType mango(2, 35);
  dispenserType fruit(1, 100);

  do {
    cout << "Products sold: " << endl;
    cout << "1. Apple Juice";
    if (apple.getNoOfItems() <= 0) {
      cout << " (out of stock)";
    };
    cout << endl;
    cout << "2. Orange Juice";
    if (orange.getNoOfItems() <= 0) {
      cout << " (out of stock)";
    };
    cout << endl;
    cout << "3. Mango Lassi";
    if (mango.getNoOfItems() <= 0) {
      cout << " (out of stock)";
    };
    cout << endl;
    cout << "4. Fruit Punch";
    if (fruit.getNoOfItems() <= 0) {
      cout << " (out of stock)";
    };
    cout << endl;
    
    do {
      cout << "Please choose your selection (1-4): ";
      cin >> selected;
    } while (selected < 1 || selected > 4);

    switch (selected) {
      case 1:
        if (apple.getNoOfItems() > 0) {
          do {
            cout << "Cost: " << apple.getCost() << endl << "Do you wish to proceed? (Y/N): ";
            cin >> agree;
          } while (agree != 'Y' && agree != 'N');

          switch (agree) {
            case 'Y':
              apple.makeSale();
              cr.acceptAmmount(apple.getCost());
              cout << "Item dispenced. Thank you.";
              break;
            
            default:
              cout << "Cancelled...";
              break;
            };
        } else {
          cout << "Item out of stock";
        };
        break;
      
      case 2:
        if (orange.getNoOfItems() > 0) {
          do {
            cout << "Cost: " << orange.getCost() << endl << "Do you wish to proceed? (Y/N): ";
            cin >> agree;
          } while (agree != 'Y' && agree != 'N');

          switch (agree) {
            case 'Y':
              orange.makeSale();
              cr.acceptAmmount(orange.getCost());
              cout << "Item dispenced. Thank you.";
              break;
            
            default:
              cout << "Cancelled...";
              break;
            };
        } else {
          cout << "Item out of stock";
        };
        break;

      case 3:
        if (mango.getNoOfItems() > 0) {
          do {
            cout << "Cost: " << mango.getCost() << endl << "Do you wish to proceed? (Y/N): ";
            cin >> agree;
          } while (agree != 'Y' && agree != 'N');

          switch (agree) {
            case 'Y':
              mango.makeSale();
              cr.acceptAmmount(mango.getCost());
              cout << "Item dispenced. Thank you.";
              break;
            
            default:
              cout << "Cancelled...";
              break;
            };
        } else {
          cout << "Item out of stock";
        };
        break;
      
      case 4:
        if (fruit.getNoOfItems() > 0) {
          do {
            cout << "Cost: " << fruit.getCost() << endl << "Do you wish to proceed? (Y/N): ";
            cin >> agree;
          } while (agree != 'Y' && agree != 'N');

          switch (agree) {
            case 'Y':
              fruit.makeSale();
              cr.acceptAmmount(fruit.getCost());
              cout << "Item dispenced. Thank you.";
              break;
            
            default:
              cout << "Cancelled...";
              break;
            };
          } else {
            cout << "Item out of stock";
          };
        break;
    };
    cout << endl << endl;
  } while (apple.getNoOfItems() > 0 || orange.getNoOfItems() > 0 || mango.getNoOfItems() > 0 || fruit.getNoOfItems() > 0);

  return 0;
};
