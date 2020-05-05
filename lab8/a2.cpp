#include <iostream>
#include <string>

using namespace std;

struct Stack {
  string data;
  Stack *next;
  Stack *prev;

  Stack(string data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  };
} *top, *bottom;

// function headers
void push(string data);
void pop();
void displayFromBottom();
void displayFromTop();
void peek();

int main() {
  push("TP01");
  push("TP02");
  push("TP03");
  pop();
  pop();
  push("TP04");
  push("TP05");
  push("TP03");
  peek();
  pop();
  peek();
  push("TP02");
  cout << endl;
  cout << "From Bottom to Top: ";
  displayFromBottom();
  cout << endl << endl;
  cout << "From Top to Bottom: ";
  displayFromTop();
  return 0;
};

void push(string data) {
  Stack *newNode = new Stack(data);

  if (bottom) {
    newNode->prev = top;
    top->next = newNode;
    top = newNode;
  } else {
    bottom = newNode;
    top = newNode;
  };

  cout << "Push " << data << " : ";
  displayFromBottom();
  cout << endl;
};
void pop() {
  if (bottom) {
    Stack *current = top->prev;
    cout << "Pop " << top->data << ": " << top->data << " is deleted!" << endl;
    delete top;
    current->next = NULL;
    top = current;

    cout << "Answer : ";
    displayFromBottom();
    cout << endl << endl;
  };
};
void displayFromTop() {
  for (Stack *current = top; current; current = current->prev)
    cout << current->data << ", ";
};
void displayFromBottom() {
  for (Stack *current = bottom; current; current = current->next)
    cout << current->data << ", ";
};
void peek() {
  if (top) {
    cout << "Peek : " << top->data << endl << endl;
  };
};
