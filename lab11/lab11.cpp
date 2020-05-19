#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  };
};

// function headers
void insert(Node *&root, int data);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
int count(Node *root);
int sum(Node *root);
int max(Node *root);
int min(Node *root);
Node *remove(Node *root, int data);

int main() {
  Node *root = nullptr;
  int n, v, d;

  cout << "How many data do you want to insert? ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << "Data " << i + 1 << " : ";
    cin >> v;
    insert(root, v);
  };

  cout << "Inorder Traversal" << endl;
  inorder(root);

  cout << endl << "Preorder Traversal" << endl;
  preorder(root);
  
  cout << endl << "Postorder Traversal" << endl;
  postorder(root);

  cout << endl << "What number do you want to remove? ";
  cin >> d;
  root = remove(root, d);

  cout << endl << "Count: " << count(root) << endl;
  cout << "Sum: " << sum(root) << endl;

  cout << endl << "Max: " << max(root) << endl;
  cout << "Min: " << min(root) << endl;

  return 0;
};

void insert(Node *&root, int data) {
  Node *temp = new Node(data);
  if (root) {
    if (root->data > data)
      insert(root->left, data);
    else if (root->data < data)
      insert(root->right, data);
  } else {
    root = temp;
  };
};
void inorder(Node *root) {
  if (root) {
    inorder(root->left);
    cout << root->data << " ";;
    inorder(root->right);
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
int count(Node *root) {
  int c = 0;
  if (root) {
    c += count(root->left);
    c += count(root->right);
    c++;
  };
  return c;
};
int sum(Node *root) {
  int s = 0;
  if (root) {
    s += sum(root->left);
    s += sum(root->right);
    s += root->data;
  };
  return s;
};
int max(Node *root) {
  int m = 0;
  if (root)
    if (root->right)
      m = max(root->right);
    else
      m = root->data;
  return m;
};
int min(Node *root) {
  int m = 0;
  if (root)
    if (root->left)
      m = min(root->left);
    else
      m = root->data;
  return m;
};
Node *remove(Node *root, int data) {
  Node *parent = nullptr, *temp = root, *successor = nullptr;
  // searching for data
  while (temp->data != data) {
    parent = temp;
    if (data < temp->data)
      temp = temp->left;
    else
      temp = temp->right;
  };

  if (temp) {
    if (temp->left && temp->right) {
      // case 1: both side subtree
      successor = temp->left; // choose left subtree
      parent = nullptr;
      // left sub replace with rightmost value
      while (successor->right) {
        parent = successor;
        successor = successor->right;
      };
      // replace current node value with the rightmost value
      temp->data = successor->data;
      if (parent)
        parent->right = successor->left;
      else
        temp->left = successor->left;
      delete successor;
    } else if (temp->right) {
      //case 2: if the node to be deleted has only right child
      if (parent->left == temp)
        parent->left = temp->right;
      else
        parent->right = temp->right;
      delete temp;
    } else if (temp->left) {
      //case 3: if the node to be deleted has only left child
      if (parent->left == temp)
        parent->left = temp->left;
      else
        parent->right = temp->left;
      delete temp;
    } else {
      // case 4: if the node to be deleted has no child // leaf node
      if (parent->left == temp)
        parent->left = nullptr;
      else
        parent->right = nullptr;
      delete temp;
    };
  }
  return root;
};
