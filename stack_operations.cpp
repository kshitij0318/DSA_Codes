#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
int stack[MAX_SIZE];
int top = -1;
void push(int element) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack overflow. Cannot push element onto stack." << endl;
    } else {
        stack[++top] = element;
        cout << element << " has been pushed onto the stack." << endl;
    }
}
void pop() {
    if (top == -1) {
        cout << "Stack is empty. Cannot pop any value." << endl;
    } else {
        cout << stack[top--] << " has been popped from the stack." << endl;
    }
}
void topElement() {
    if (top == -1) {
        cout << "Stack is empty. No top element is present." << endl;
    } else {
        cout << "Top element in given stack is: " << stack[top] << endl;
    }
}
bool isEmpty() {
    return top == -1;
}
int size() {
    return top + 1;
}
int main() {/

    int choice, element;
    do {
        cout<<"\n--------------------------------";
        cout << "\nStack Menu Driven:";
        cout << "\n1. Push Element";
        cout << "\n2. Pop Element";
        cout << "\n3. Top Element";
        cout << "\n4. Is Empty?";
        cout << "\n5. Size of Stack";
        cout << "\n6. Quit";
        cout << "\nEnter your choice (1-6): ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to push onto stack: ";
                cin >> element;
                push(element);
                break;
            case 2:
                pop(); // Pops top value from stack.
                break;
            case 3:
                topElement(); //Gives us top elements in stack without making any changes to the stack itself.
                break;
            case 4:
                if (isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                cout << "Size of stack: " << size() << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);
    return 0;    
}