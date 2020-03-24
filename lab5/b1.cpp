#include <iostream>
using namespace std;

struct Song {
  public:
    int no;
    string artist;
    string name;
    int released;
    string genre;
    double length;
    Song *next;
} *head, *temp;

// function headers
Song *createNewNode(int no, string artist, string name, int released, string genre, double length);
void insertToStart(int no, string artist, string name, int released, string genre, double length);
void insertToEnd(int no, string artist, string name, int released, string genre, double length);
void displayList();

int main() {
  // initialise
  head = NULL;

  // existing song list
  insertToEnd(1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58);
  insertToEnd(2, "Taylor Swift", "You Belong With Me", 2008, "Pop", 3.48);
  insertToEnd(3, "The Cranberries", "Promises", 1999, "Rock", 4.30);

  // display
  displayList();

  // insert to start
  insertToStart(4, "Maria Carey", "All I Want For Christmas Is You", 1994, "Seasonal", 3.55);

  // display
  displayList();

  // insert to end
  insertToEnd(5, "Selena Gomez, Kygo", "It Ain't Me", 2017, "Dance-pop", 3.41);

  // display
  displayList();

  return 0;
};

Song *createNewNode(int no, string artist, string name, int released, string genre, double length) {
  // create structure
  Song *newNode = new Song;
  // set value
  newNode->no = no;
  newNode->artist = artist;
  newNode->name = name;
  newNode->released = released;
  newNode->genre = genre;
  newNode->length = length;
  newNode->next = NULL;

  return newNode;
};

void insertToStart(int no, string artist, string name, int released, string genre, double length) {
  // build new node
  Song *newNode = createNewNode(no, artist, name, released, genre, length);

  // insert new node
  if (head == NULL) {
    // if list is empty, new node is first item
    head = newNode;
  } else {
    // link the new node to the first item
    newNode->next = head;
    // change head address to the new node to make it as first item
    head = newNode;
  };
};

void insertToEnd(int no, string artist, string name, int released, string genre, double length) {
  // build new node
  Song *newNode = createNewNode(no, artist, name, released, genre, length);

  // insert new node
  if (head == NULL) {
    // if list is empty, new node is first item
    head = newNode;
  } else {
    // find last node
    temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    };
    // link last node to the new node to make new node the new last node
    temp->next = newNode;
  };
};

void displayList() {
  // loop and display all in linked list
  temp = head;
  while (temp != NULL) {
    cout << temp->no << " " << temp->artist << " " << temp->name << " " << temp->released << " " << temp->genre << " " << temp->length << endl;
    temp = temp->next;
  };
  cout << endl;
};
