#include <iostream>

using namespace std;

class Population {
  private:
    int population;
    int numOfBirths;
    int numOfDeaths;

  public:
    Population(int pop, int births, int deaths) {
      population = pop;
      numOfBirths = births;
      numOfDeaths = deaths;
    };

    double getBirthRate() {
      return (double) numOfBirths / (double) population;
    };

    double getDeathRate() {
      return (double) numOfDeaths / (double) population;
    };
};

int main() {
  int pop, births, deaths;

  do {
    cout << "Population: ";
    cin >> pop;
  } while (pop < 1);

  do {
    cout << "Births: ";
    cin >> births;
  } while (births < 0);

  do {
    cout << "Deaths: ";
    cin >> deaths;
  } while (deaths < 0);

  Population country(pop, births, deaths);

  cout << "Birth Rate: " << country.getBirthRate() << endl;
  cout << "Death Rate: " << country.getDeathRate() << endl;

  return 0;
};
