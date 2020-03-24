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
void insertToSorted(int no, string artist, string name, int released, string genre, double length);
void displayList();

int main() {
  // initialise
  head = NULL;

  // existing song list
  insertToSorted(1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58);
  insertToSorted(2, "Taylor Swift", "You Belong With Me", 2008, "Pop", 3.48);
  insertToSorted(3, "The Cranberries", "Promises", 1999, "Rock", 4.30);

  // display
  displayList();

  // insert to sorted list
  insertToSorted(4, "Maria Carey", "All I Want For Christmas Is You", 1994, "Seasonal", 3.55);
  insertToSorted(5, "Selena Gomez, Kygo", "It Ain't Me", 2017, "Dance-pop", 3.41);

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

void insertToSorted(int no, string artist, string name, int released, string genre, double length) {
  // build new node
  Song *newNode = createNewNode(no, artist, name, released, genre, length);

  // insert new node
  if (head == NULL) {
    // if list is empty, new node is first item
    head = newNode;
  } else if (no <= head->no) {
    // if song number is less than the head song number, make new node as first item
    newNode->next = head;
    head = newNode;
  } else {
    // if song number is more than the head song number
    temp = head;
    while (temp->next != NULL) {
      if (no <= temp->next->no) {
        // find song number that is less than temp song number to stop iteration
        break;
      };
      temp = temp->next;
    };
    // link the new node to the next node
    newNode->next = temp->next;
    // link the previous node to the new node
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
