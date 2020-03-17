#include <iostream>

using namespace std;

class Employee {
  private:
    string name;
    int idNumber;
    string department;
    string position;

  public:
    Employee(string na, int id, string dep, string pos) {
      name = na;
      idNumber = id;
      department = dep;
      position = pos;
    };

    Employee(string na, int id) {
      Employee(na, id, "", "");
    };

    Employee() {
      Employee("", 0, "", "");
    }
    
    void setName(string na) {
      name = na;
    };

    string getName() {
      return name;
    };

    int getIdNumber() {
      return idNumber;
    };

    void setDepartment(string dep) {
      department = dep;
    };

    string getDepartment() {
      return department;
    };

    void setPosition(string pos) {
      position = pos;
    };

    string getPosition() {
      return position;
    }
};

int main() {
  Employee emp1("Susan", 47899, "Accounting", "Vice President");
  Employee emp2("Matthew", 34522, "IT", "Programmer");
  Employee emp3("James", 65881, "Manufactoring", "Engineer");

  cout << "Name: " << emp1.getName() << endl;
  cout << "ID: " << emp1.getIdNumber() << endl;
  cout << "Department: " << emp1.getDepartment() << endl;
  cout << "Position: " << emp1.getPosition() << endl << endl;

  cout << "Name: " << emp2.getName() << endl;
  cout << "ID: " << emp2.getIdNumber() << endl;
  cout << "Department: " << emp2.getDepartment() << endl;
  cout << "Position: " << emp2.getPosition() << endl << endl;

  cout << "Name: " << emp3.getName() << endl;
  cout << "ID: " << emp3.getIdNumber() << endl;
  cout << "Department: " << emp3.getDepartment() << endl;
  cout << "Position: " << emp3.getPosition() << endl;

  return 0;
}
