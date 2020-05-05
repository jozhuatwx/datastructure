#include <iostream>
#include <string>

using namespace std;

struct Student {
  int ID;
  string name;
  string intake;

  Student() {
    this->ID = -1;
    this->name = "";
    this->intake = "";
  };

  Student(int ID, string name, string intake) {
    this->ID = ID;
    this->name = name;
    this->intake = intake;
  };
};

struct Stack {
  int top;
  Student student[10];

  Stack() {
    this->top = -1;
  };
} stack;

// function headers
void push();
void pop();
void displayFromBottom();
void displayFromTop();

int main() {
  int input = 0;

  do {
    cout << "(1) Push student" << endl;
    cout << "(2) Pop student" << endl;
    cout << "(3) Display from bottom" << endl;
    cout << "(4) Display from top" << endl;
    cout << "(5) Exit" << endl;
    cout << "Enter option: ";
    cin >> input;

    switch (input) {
      case 1:
        push();
        break;

      case 2:
        pop();
        break;

      case 3:
        displayFromBottom();
        break;

      case 4:
        displayFromTop();
        break;

      default:
        break;
    };

    cout << endl;
  } while (input != 5);
  return 0;
};

void push() {
  int ID;
  string name, intake;

  cout << "Enter student id: ";
  cin >> ID;

  cout << "Enter student name: ";
  cin >> name;

  cout << "Enter intake: ";
  cin >> intake;
  
  Student newNode = Student(ID, name, intake);
  stack.student[++stack.top] = newNode;
};
void pop() {
  cout << "Pop ID: " << stack.student[stack.top].ID << endl;
  stack.student[stack.top--] = Student();
};
void displayFromBottom() {
  for (int i = 0; i <= stack.top; i++)
    cout << stack.student[i].ID << " - " << stack.student[i].name << " - " << stack.student[i].intake << endl;
};
void displayFromTop() {
  for (int i = stack.top; i >= 0; i--)
    cout << stack.student[i].ID << " - " << stack.student[i].name << " - " << stack.student[i].intake << endl;
};
