#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int size;

public:
    void init(int s) {
        size = s;
        top = -1;
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Overflow\n";
        } else {
            top++;
            arr[top] = x;
            cout << "Inserted\n";
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Underflow\n";
        } else {
            cout << "Deleted element: " << arr[top] << endl;
            top--;
        }
    }

    void peek() {
        if (top == -1) {
            cout << "Stack empty\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack empty\n";
        } else {
            cout << "Stack: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    int isEmpty() {
        return top == -1;
    }

    int isFull() {
        return top == size - 1;
    }
};

int main() {
    Stack s;
    int n;
    cout << "Enter stack size: ";
    cin >> n;
    s.init(n);

    int ch, val;
    do {
        cout << "\n1.Push 2.Pop 3.Peek 4.isEmpty 5.isFull 6.Display 7.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                if (s.isEmpty()) cout << "Empty\n";
                else cout << "Not Empty\n";
                break;
            case 5:
                if (s.isFull()) cout << "Full\n";
                else cout << "Not Full\n";
                break;
            case 6:
                s.display();
                break;
            case 7:
                cout << "Exit\n";
                break;
            default:
                cout << "Wrong choice\n";
        }
    } while (ch != 7);

    return 0;
}