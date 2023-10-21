#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};
class AVLTree {
public:
    Node* root;
    // Function to calculate the height of a node
    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }
    // Function to calculate the balance factor of a node
    int balanceFactor(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }
    // Functions for rotations
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    Node* leftRightRotate(Node* node) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    Node* rightLeftRotate(Node* node) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    // Functions for insertion, deletion, and search
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            Node* newNode = new Node;
            newNode->data = key;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->height = 1;
            return newNode;
        }
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node; // Duplicate keys are not allowed
        // Update height
        node->height = 1 + max(height(node->left), height(node->right));
        // Perform rotations
        int balance = balanceFactor(node);
        if (balance > 1) {
            if (key < node->left->data)
                return rightRotate(node);
            else
                return leftRightRotate(node);
        }
        if (balance < -1) {
            if (key > node->right->data)
                return leftRotate(node);
            else
                return rightLeftRotate(node);
        }
        return node;
    }
    Node* findMinValueNode(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }
    Node* remove(Node* node, int key) {
        if (node == nullptr) return node;
        if (key < node->data)
            node->left = remove(node->left, key);
        else if (key > node->data)
            node->right = remove(node->right, key);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMinValueNode(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        if (node == nullptr) return node;
        // Update height
        node->height = 1 + max(height(node->left), height(node->right));
        // Perform rotations
        int balance = balanceFactor(node);
        if (balance > 1) {
            if (balanceFactor(node->left) >= 0)
                return rightRotate(node);
            else
                return leftRightRotate(node);
        }
        if (balance < -1) {
            if (balanceFactor(node->right) <= 0)
                return leftRotate(node);
            else
                return rightLeftRotate(node);
        }
        return node;
    }
    Node* search(Node* node, int key) {
        if (node == nullptr || node->data == key)
            return node;

        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }
    // Function to display the tree (inorder traversal)
    void display(Node* node) {
        if (node != nullptr) {
            display(node->left);
            cout << node->data << " ";
            display(node->right);
        }
    }
    AVLTree() {
        root = nullptr;
    }
    ~AVLTree() {
        // Implement a destructor to free allocated memory if needed.
    }
};
int main() {
    AVLTree tree;
    int choice, key;
    do {
        cout << "AVL Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                tree.root = tree.insert(tree.root, key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                tree.root = tree.remove(tree.root, key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if (tree.search(tree.root, key))
                    cout << "Key found in the tree.\n";
                else
                    cout << "Key not found in the tree.\n";
                break;
            case 4:
                cout << "AVL Tree:\n";
                tree.display(tree.root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}