#include <iostream>

using namespace std;

struct Queue {
  char c;
  Queue *next;
  Queue *prev;

  Queue(char c) {
    this->c = c;
    this->next = nullptr;
    this->prev = nullptr;
  };
} *front, *back;

// function header
void enqueue(char c);
char dequeue();
bool check(string input);

int main() {
  string input;

  cout << "Enter text: ";
  cin >> input;

  bool palindrome = check(input);

  if (palindrome)
    cout << "Input is a palindrome";
  else
    cout << "Input is not a palindrome";

  return 1;
};

void enqueue(char c) {
  Queue *newQueue = new Queue(c);

  if (front) {
    back->prev = newQueue;
    newQueue->next = back;
    back = newQueue;
  } else {
    front = newQueue;
    back = newQueue;
  };
};
char dequeue() {
  if (front) {
    Queue *current = front;
    front = front->prev;
    if (front)
      front->next = nullptr;
    return current->c;
  };
};
bool check(string input) {
  int i = 0;
  int size = input.size();
  for (; i < (size / 2); i++)
    enqueue(input[i]);

  if (input.size() % 2 != 0)
    i++;

  int temp = i;
  size--;

  for (; size > temp; size--)
    if (dequeue() != input[size])
      return false;

  return true;
};
