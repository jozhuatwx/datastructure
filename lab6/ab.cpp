#include <iostream>
using namespace std;

struct Student {
  public:
    int id;
    Student *next;
} *head, *temp, *sortedHead, *sortedTemp;

// function headers
Student *createNewNode(int id);
void insertToStart(int id, int *size);
void insertToSorted(int id);
void insertToEnd(int id, int *size);

void searchID(int id);

void deleteAll(Student *tempHead);
void deleteFromStart(int *size);
void deleteFromIndex(int index, int *size);
void deleteFromEnd(int *size);

void displaySortedList();
void displayList(Student *tempHead);

int main() {
  // initialise
  head = NULL;
  int size = 0;

  for (int i = 0; i < 5; i++)
    insertToEnd(i + 1, &size);

  // delete
  deleteFromIndex(3, &size);

  // search
  searchID(4);
  searchID(3);

  // display sorted
  displaySortedList();

  // display
  displayList(head);

  return 0;
};

Student *createNewNode(int id) {
  // create structure
  Student *newNode = new Student;
  // set value
  newNode->id = id;
  newNode->next = NULL;

  return newNode;
};

void insertToStart(int id, int *size) {
  // build new node
  Student *newNode = createNewNode(id);

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

void insertToSorted(int id) {
  // build new node
  Student *newNode = createNewNode(id);

  // insert new node
  if (sortedHead == NULL) {
    // if list is empty, new node is first item
    sortedHead = newNode;
  } else if (id <= sortedHead->id) {
    // if song number is less than the head song number, make new node as first item
    newNode->next = sortedHead;
    sortedHead = newNode;
  } else {
    // if song number is more than the head song number
    sortedTemp = sortedHead;
    while (sortedTemp->next != NULL) {
      if (id <= sortedTemp->next->id) {
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

void insertToEnd(int id, int *size) {
  // build new node
  Student *newNode = createNewNode(id);

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

void searchID(int id) {
  temp = head;
  bool found = false;
  while (temp != NULL) {
    if (temp->id == id) {
      found = true;
      break;
    };
    temp = temp->next;
  };
  if (found)
    cout << "Student found" << endl;
  else
    cout << "Student not found" << endl;
};

void deleteAll(Student *tempHead) {
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
    Student *toDelete = head;
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
      Student *toDelete = head;
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
      Student *beforeLast = head;
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
    insertToSorted(temp->id);
    temp = temp->next;
  };

  sortedTemp = sortedHead;

  while (sortedTemp != NULL) {
    cout << sortedTemp->id << endl;
    sortedTemp = sortedTemp->next;
  };
  cout << endl;
  deleteAll(sortedTemp);
  deleteAll(sortedHead);
};

void displayList(Student *tempHead) {
  // loop and display all in linked list
  temp = tempHead;
  while (temp != NULL) {
    cout << temp->id << endl;
    temp = temp->next;
  };
  cout << endl;
};
