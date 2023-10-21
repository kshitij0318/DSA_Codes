#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class Stack {
public:
    Node* stack[20];
    int top;
    Stack() {
        top = -1;
    }
    void push(Node* item) {
        if (top >= 20 - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        stack[++top] = item;
    }
    Node* pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return nullptr;
        }
        return stack[top--];
    }
    bool isEmpty() {
        return top == -1;
    }
};
class Tree {
public:
    Node* root;
    Tree() {
        root = nullptr;
    }
    void insert(int data) {
        Node* temp = new Node(data);
        if (root == nullptr) {
            root = temp;
            return;
        }
        Node* previous = nullptr;
        Node* current = root;
        while (current != nullptr) {
            previous = current;
            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }
        if (data < previous->data) {
            previous->left = temp;
        }
        else {
            previous->right = temp;
        }
    }
    void iterativeDFS() {
        if (root == nullptr)
            return;
        Node* current = root;
        Stack stack;
        while (current != nullptr || !stack.isEmpty()) {
            while (current != nullptr) {
                cout << current->data << " ";
                stack.push(current);
                current = current->left;
            }
            current = stack.pop();
            current = current->right;
        }
    }
    void inorder() {
        if (root == nullptr)
            return;
        Node* current = root;
        Stack stack;
        while (current != nullptr || !stack.isEmpty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }
            current = stack.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
    void preorder() {
        if (root == nullptr)
            return;
        Node* current = root;
        Stack stack;
        stack.push(current);
        while (!stack.isEmpty()) {
            current = stack.pop();
            cout << current->data << " ";
            if (current->right != nullptr)
                stack.push(current->right);
            if (current->left != nullptr)
                stack.push(current->left);
        }
    }
    void postorder() {
        if (root == nullptr)
            return;
        Node* current = root;
        Stack stack1, stack2;
        stack1.push(current);
        while (!stack1.isEmpty()) {
            current = stack1.pop();
            stack2.push(current);
            if (current->left != nullptr)
                stack1.push(current->left);
            if (current->right != nullptr)
                stack1.push(current->right);
        }
        while (!stack2.isEmpty()) {
            current = stack2.pop();
            cout << current->data << " ";
        }
    }
    void bfs() {
        if (root == nullptr)
            return;
        Node* queue[20];
        int front = -1;
        int rear = -1;
        queue[++rear] = root;
        while (front != rear) {
            Node* current = queue[++front];
            cout << current->data << " ";
            if (current->left != nullptr)
                queue[++rear] = current->left;
            if (current->right != nullptr)
                queue[++rear] = current->right;
        }
    }
    bool search(Node* current, int key) {
        if (current == nullptr) {
            return false;
        }
        if (current->data == key) {
            return true;
        }
        else if (key < current->data) {
            return search(current->left, key);
        }
        else {
            return search(current->right, key);
        }
    }
    bool search(int key) {
        return search(root, key);
    }
};
int main() {
    Tree tree;
    int choice;
    int key;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Inorder traversal\n";
        cout << "3. Preorder traversal\n";
        cout << "4. Postorder traversal\n";
        cout << "5. Iterative DFS traversal\n";
        cout << "6. BFS traversal\n";
        cout << "7. Search for a key\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> key;
            tree.insert(key);
            break;
        case 2:
            cout << "Inorder traversal: ";
            tree.inorder();
            break;
        case 3:
            cout << "Preorder traversal: ";
            tree.preorder();
            break;
        case 4:
            cout << "Postorder traversal: ";
            tree.postorder();
            break;
        case 5:
            cout << "Iterative DFS traversal: ";
            tree.iterativeDFS();
            break;
        case 6:
            cout << "BFS traversal: ";
            tree.bfs();
            break;
        case 7:
            cout << "Enter key to search: ";
            cin >> key;
            if (tree.search(key))
                cout << key << " found in the tree." << endl;
            else
                cout << key << " not found in the tree." << endl;
            break;
        case 8:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 8);
    return 0;
}