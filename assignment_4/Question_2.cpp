#include <iostream>
using namespace std;

#define MAX_SIZE 5

class CircularQueue {
public:
    int arr[MAX_SIZE];
    int front;
    int rear;

    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ( (rear + 1) % MAX_SIZE ) == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = x;
        cout << "Enqueued: " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }

    void peek() {
        if (!isEmpty()) {
            cout << "Front: " << arr[front] << endl;
        } else {
            cout << "Queue Empty\n";
        }
    }
};

int main() {
    CircularQueue q;

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