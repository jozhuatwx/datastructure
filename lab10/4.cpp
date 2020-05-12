#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

// function headers
Node *insert(int index);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);

int a[] = {3, 5, 9, 6, 8, 20, 10, '\0', '\0', 9, '\0', '\0', '\0', '\0', '\0', '\0', '\0'};

int main() {  
  Node *root = nullptr;
  root = insert(0);
  cout << "Inorder Traversal" << endl;
  inorder(root);
  cout << endl << "Preorder Traversal" << endl;
  preorder(root);
  cout << endl << "Postorder Traversal" << endl;
  postorder(root);

  return 0;
};

Node *insert(int index) {
  Node *temp = nullptr;
  if (a[index]) {
    temp = new Node();
    temp->left = insert(2 * index + 1);
    temp->data = a[index];
    temp->right = insert(2 * index + 2);
  };
  return temp;
};
void inorder(Node *root) {
  if (root) {
    inorder(root->left);
    cout << root->data << " ";;
    inorder(root-> right);
  };
};
void preorder(Node *root) {
  if (root) {
    cout << root->data << " ";;
    preorder(root->left);
    preorder(root->right);
  };
};
void postorder(Node *root) {
  if (root) {
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";;
  };
};
