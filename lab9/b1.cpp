#include <iostream>

using namespace std;

struct Queue {
  string id;
  Queue *next;
  Queue *prev;

  Queue(string id) {
    this->id = id;
    this->next = nullptr;
    this->prev = nullptr;
  };
} *front, *back;

// function header
void enqueue(string id);
void display();
void move(int index);

int main() {
  enqueue("5");
  enqueue("11");
  enqueue("34");
  enqueue("67");
  enqueue("43");
  enqueue("55");

  int index;

  display();

  cout << "Which element you want to move? ";
  cin >> index;

  move(index - 1);

  return 1;
};

void enqueue(string id) {
  Queue *newQueue = new Queue(id);

  if (front) {
    back->prev = newQueue;
    newQueue->next = back;
    back = newQueue;
  } else {
    front = newQueue;
    back = newQueue;
  };
};

void display() {
  for (Queue *current = front; current; current = current->prev)
    cout << current->id << ",";
  cout << endl;
};

void move(int index) {
  Queue *current = front;
  for (int i = 0; i < index; i++)
    current = current->prev;

  current->prev->next = current->next;
  current->next->prev = current->prev;

  current->prev = front;
  current->next = nullptr;

  front = current;

  display();
}
