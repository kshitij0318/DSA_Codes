#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> myStack;
    int choice, element;
    do {
        cout << "\nStack Menu:";
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
                cout << "Enter element to push: ";
                cin >> element;
                myStack.push(element);
                cout << element << " has been pushed onto the stack.";
                break;
            case 2:
                if (!myStack.empty()) {
                    element = myStack.top();
                    myStack.pop();
                    cout << element << " has been popped from the stack.";
                } else {
                    cout << "Stack is empty. Cannot pop.";
                }
                break;
            case 3:
                if (!myStack.empty()) {
                    element = myStack.top();
                    cout << "Top element: " << element;
                } else {
                    cout << "Stack is empty. No top element.";
                }
                break;
            case 4:
                if (myStack.empty()) {
                    cout << "Stack is empty.";
                } else {
                    cout << "Stack is not empty.";
                }
                break;
            case 5:
                cout << "Size of stack: " << myStack.size();
                break;
            case 6:
                cout << "Exiting program.";
                break;
            default:
                cout << "Invalid choice. Please try again.";
                break;
        }
    } while (choice != 6);
    return 0;
}