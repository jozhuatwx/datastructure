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
} *head, *temp, *sortedHead, *sortedTemp;

// function headers
Song *createNewNode(int no, string artist, string name, int released, string genre, double length);
void insertToStart(int no, string artist, string name, int released, string genre, double length, int *size);
void insertToSorted(int no, string artist, string name, int released, string genre, double length);
void insertToEnd(int no, string artist, string name, int released, string genre, double length, int *size);

int searchIndexArtist(string artist);
int searchIndexNo(int no);
void searchGenre(string genre);

void deleteAll(Song *tempHead);
void deleteFromStart(int *size);
void deleteFromIndex(int index, int *size);
void deleteFromEnd(int *size);

void displaySortedList();
void displayList(Song *tempHead);

int main() {
  // initialise
  head = NULL;
  int size = 0;

  // existing song list
  insertToEnd(1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58, &size);
  insertToEnd(2, "Taylor Swift", "You Belong With Me", 2008, "Pop", 3.48, &size);
  insertToEnd(3, "The Cranberries", "Promises", 1999, "Rock", 4.30, &size);

  // insert to start
  insertToStart(4, "Maria Carey", "All I Want For Christmas Is You", 1994, "Seasonal", 3.55, &size);

  // insert to end
  insertToEnd(5, "Selena Gomez, Kygo", "It Ain't Me", 2017, "Dance-pop", 3.41, &size);

  // delete from start
  // deleteFromStart(&size);

  // delete from end
  // deleteFromEnd(&size);

  // delete based on artist name
  // deleteFromIndex(searchIndexArtist("Taylor Swift"), &size);

  // delete based on song name
  // deleteFromIndex(searchIndexNo(3), &size);

  // search based on genre
  searchGenre("Pop");

  // display sorted
  displaySortedList();

  // display
  displayList(head);

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

void insertToStart(int no, string artist, string name, int released, string genre, double length, int *size) {
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
  *size += 1;
};

void insertToSorted(int no, string artist, string name, int released, string genre, double length) {
  // build new node
  Song *newNode = createNewNode(no, artist, name, released, genre, length);

  // insert new node
  if (sortedHead == NULL) {
    // if list is empty, new node is first item
    sortedHead = newNode;
  } else if (no <= sortedHead->no) {
    // if song number is less than the head song number, make new node as first item
    newNode->next = sortedHead;
    sortedHead = newNode;
  } else {
    // if song number is more than the head song number
    sortedTemp = sortedHead;
    while (sortedTemp->next != NULL) {
      if (no <= sortedTemp->next->no) {
        // find song number that is less than temp song number to stop iteration
        break;
      };
      sortedTemp = sortedTemp->next;
    };
    // link the new node to the next node
    newNode->next = sortedTemp->next;
    // link the previous node to the new node
    sortedTemp->next = newNode;
  };
};

void insertToEnd(int no, string artist, string name, int released, string genre, double length, int *size) {
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
  *size += 1;
};

int searchIndexArtist(string artist) {
  Song *temp = head;
  int index = 0;
  while (temp != NULL) {
    if (temp->artist == artist)
      return index;
    else
      temp = temp->next;
    index++;
  };
  // node not found
  return -1;
};

int searchIndexNo(int no) {
  Song *temp = head;
  int index = 0;
  while (temp != NULL) {
    if (temp->no == no)
      return index;
    else
      temp = temp->next;
    index++;
  };
  // node not found
  return -1;
};

void searchGenre(string genre) {
  temp = head;
  while (temp != NULL) {
    if (temp->genre == genre)
      cout << temp->no << " " << temp->artist << " " << temp->name << " " << temp->released << " " << temp->genre << " " << temp->length << endl;
    temp = temp->next;
  };
  cout << endl;
};

void deleteAll(Song *tempHead) {
  temp = tempHead;
  while (tempHead != NULL) {
    temp = temp->next;
    delete tempHead;
    tempHead = temp;
  };
};

void deleteFromStart(int *size) {
  // check if there is any nodes
  if (*size > 0) {
    Song *toDelete = head;
    head = head->next;
    delete toDelete;
    *size -= 1;
  };
};

void deleteFromIndex(int index, int *size) {
  // check if index is out of bounds
  if (index < *size) {
    if (index > 0) {
      temp = NULL;
      Song *toDelete = head;
      for (int i = 0; i < index; i++) {
        temp = toDelete;
        toDelete = toDelete->next;
      };
      temp->next = toDelete->next;
      delete toDelete;
      *size -= 1;
    } else if (index == 0) {
      deleteFromStart(size);
    };
  };
};

void deleteFromEnd(int *size) {
  // check if there is any nodes
  if (*size > 0) {
    if (*size > 1) {
      Song *beforeLast = head;
      while (beforeLast->next->next != NULL)
        beforeLast = beforeLast->next;
      delete beforeLast->next;
      beforeLast->next = NULL;
    } else {
      delete head;
      head = NULL;
    };
    *size -= 1;
  };
}

void displaySortedList() {
  temp = head;
  sortedHead = NULL;

  while (temp != NULL) {
    insertToSorted(temp->no, temp->artist, temp->name, temp->released, temp->genre, temp->length);
    temp = temp->next;
  };

  sortedTemp = sortedHead;

  while (sortedTemp != NULL) {
    cout << sortedTemp->no << " " << sortedTemp->artist << " " << sortedTemp->name << " " << sortedTemp->released << " " << sortedTemp->genre << " " << sortedTemp->length << endl;
    sortedTemp = sortedTemp->next;
  };
  cout << endl;
  deleteAll(sortedTemp);
  deleteAll(sortedHead);
};

void displayList(Song *tempHead) {
  // loop and display all in linked list
  temp = tempHead;
  while (temp != NULL) {
    cout << temp->no << " " << temp->artist << " " << temp->name << " " << temp->released << " " << temp->genre << " " << temp->length << endl;
    temp = temp->next;
  };
  cout << endl;
};
