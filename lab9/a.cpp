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

// function headers
void enqueue(string id);
void dequeue();
void display_from_front();
void display_from_back();

int main() {
  front = back = nullptr;

  enqueue("TP01");
  enqueue("TP02");
  enqueue("TP03");
  dequeue();
  enqueue("TP04");
  enqueue("TP05");
  dequeue();
  enqueue("TP02");

  cout << "From front to back:" << endl;
  display_from_front();

  cout << "From back to front:" << endl;
  display_from_back();

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
void dequeue() {
  if (front) {
    Queue *current = front;
    cout << "Removed ID: " << current->id << endl;
    front = front->prev;
    front->next = nullptr;
    delete current;
  };
};
void display_from_front() {
  for (Queue *current = front; current; current = current->prev)
    cout << "ID: " << current->id << endl;
};
void display_from_back() {
  for (Queue *current = back; current; current = current->next)
    cout << "ID: " << current->id << endl;
};
