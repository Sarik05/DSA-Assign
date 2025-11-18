#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue {
public:
    int arr[MAX_SIZE];
    int frontIndex;
    int rearIndex;

    Queue() {
        frontIndex = -1;
        rearIndex = -1;
    }

    bool isEmpty() {
        return (frontIndex == -1 && rearIndex == -1);
    }

    bool isFull() {
        return (rearIndex == MAX_SIZE - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue full\n";
            return;
        }

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            rearIndex++;
        }

        arr[rearIndex] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }

        cout << "Dequeued: " << arr[frontIndex] << endl;

        if (frontIndex == rearIndex) {
            frontIndex = -1;
            rearIndex = -1;
        } else {
            frontIndex++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }

        cout << "Queue: ";
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (!isEmpty()) {
            cout << "Front: " << arr[frontIndex] << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.peek();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();

    return 0;
}