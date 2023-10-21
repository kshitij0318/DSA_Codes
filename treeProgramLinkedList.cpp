#include<iostream>
#include<queue>
using namespace std;
class Node 
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int value) 
  {
    data = value;
    left = nullptr;
    right = nullptr;
  }
};
class Tree 
{
public:
  Node *root;
  Tree() 
  {
    root = nullptr;
  }
  void insert(int data)
  {
    Node *temp = new Node(data);
    if (root == nullptr)
    {
        root = temp;
        return;
    }
    Node *previous = nullptr;
    Node *current = root;
    while (current != nullptr)
    {
        previous = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if (data < previous->data)
    {
      previous->left = temp;
    }
    else
    {
      previous->right = temp;
    }
  }
  void inorder(Node *current)
  {
    if (current == nullptr)
      return;
    inorder(current->left);
    cout << current->data << " ";
    inorder(current->right);
  }
  void preorder(Node *current)
  {
    if (current == nullptr)
      return;
    cout << current->data << " ";
    preorder(current->left);
    preorder(current->right);
  }
  void postorder(Node *current)
  {
    if (current == nullptr)
      return;
    postorder(current->left);
    postorder(current->right);
    cout << current->data << " ";
  }
  void dfs(Node *current) 
  {
    if (current == nullptr) 
      return;
    cout << current->data << " ";
    dfs(current->left);
    dfs(current->right);
  }
  void bfs() 
  {
    if (root == nullptr) 
      return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) 
    {
      Node *current = q.front();
      q.pop();
      cout << current->data << " ";
      if (current->left != nullptr) 
        q.push(current->left);
      if (current->right != nullptr) 
        q.push(current->right);
    }
  }  
  bool search(Node* current, int key) {
    if (current == nullptr) {
      return false;
    }
    if (current->data == key) {
      return true;
    } else if (key < current->data) {
      return search(current->left, key);
    } else {
      return search(current->right, key);
    }
  }

  bool search(int key) {
    return search(root, key);
  }
};
int main() 
{
  Tree tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(1);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);
  cout << "Inorder traversal output will be as follows: ";
  tree.inorder(tree.root);
  cout << endl;
  cout << "Preorder traversal will be as follows: ";
  tree.preorder(tree.root);
  cout << endl;
  cout << "Postorder traversal will be as follows: ";
  tree.postorder(tree.root);
  cout << endl;
  cout << "DFS traversal will be as follows: ";
  tree.dfs(tree.root);
  cout << endl;
  cout << "BFS traversal will be as follows: ";
  tree.bfs();
  cout << endl;
  int key_to_search = 4;
  if (tree.search(key_to_search)) {
    cout << key_to_search << " found in the tree at address: " << &key_to_search << endl;
  } else {
    cout << key_to_search << " not found in the tree." << endl;
  }
  return 0;
}




// inorder 60 70 72 75 80 85 90 100 105 110