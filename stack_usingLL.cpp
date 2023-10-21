#include <iostream>
using namespace std;
struct SLLNode {
    int data;
    SLLNode* next;
};
struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
};
class StackUsingSLL {
private:
    SLLNode* top;
public:
    StackUsingSLL() {
        top = nullptr;
    }
    // Push operation for SLL
    void push(int value) {
        SLLNode* newNode = new SLLNode;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    // Pop operation for SLL
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        SLLNode* temp = top;
        top = top->next;
        delete temp;
    }
    // Peek operation for SLL
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        }
        return top->data;
    }
    // Display operation for SLL
    void display() {
        SLLNode* current = top;
        cout << "Stack (SLL): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    // Check if SLL stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};
class StackUsingDLL {
private:
    DLLNode* top;
public:
    StackUsingDLL() {
        top = nullptr;
    }
    // Push operation for DLL
    void push(int value) {
        DLLNode* newNode = new DLLNode;
        newNode->data = value;
        newNode->next = top;
        newNode->prev = nullptr;
        if (top != nullptr) {
            top->prev = newNode;
        }
        top = newNode;
    }
    // Pop operation for DLL
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        DLLNode* temp = top;
        top = top->next;
        if (top != nullptr) {
            top->prev = nullptr;
        }
        delete temp;
    }
    // Peek operation for DLL
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        }
        return top->data;
    }
    // Display operation for DLL
    void display() {
        DLLNode* current = top;
        cout << "Stack (DLL): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    // Check if DLL stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};
int main() {
    StackUsingSLL sllStack;
    StackUsingDLL dllStack;
    int choice;
    int value;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Push to SLL Stack" << endl;
        cout << "2. Push to DLL Stack" << endl;
        cout << "3. Pop from SLL Stack" << endl;
        cout << "4. Pop from DLL Stack" << endl;
        cout << "5. Peek SLL Stack" << endl;
        cout << "6. Peek DLL Stack" << endl;
        cout << "7. Display SLL Stack" << endl;
        cout << "8. Display DLL Stack" << endl;
        cout << "9. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push to SLL Stack: ";
                cin >> value;
                sllStack.push(value);
                break;
            case 2:
                cout << "Enter value to push to DLL Stack: ";
                cin >> value;
                dllStack.push(value);
                break;
            case 3:
                sllStack.pop();
                break;
            case 4:
                dllStack.pop();
                break;
            case 5:
                cout << "SLL Stack Peek: " << sllStack.peek() << endl;
                break;
            case 6:
                cout << "DLL Stack Peek: " << dllStack.peek() << endl;
                break;
            case 7:
                sllStack.display();
                break;
            case 8:
                dllStack.display();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
