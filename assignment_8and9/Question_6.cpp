#include <iostream>
#include <vector>
using namespace std;

struct PriorityQueue {
    vector<int> heap;

    void push(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] >= heap[i]) break;
            int t = heap[p];
            heap[p] = heap[i];
            heap[i] = t;
            i = p;
        }
    }

    int top() {
        if (heap.empty()) {
            cout << "priority queue empty\n";
            return -1;
        }
        return heap[0];
    }

    void pop() {
        if (heap.empty()) {
            cout << "priority queue empty\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        int n = heap.size();
        int i = 0;

        while (1) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int big = i;

            if (left < n && heap[left] > heap[big]) big = left;
            if (right < n && heap[right] > heap[big]) big = right;

            if (big == i) break;

            int t = heap[i];
            heap[i] = heap[big];
            heap[big] = t;

            i = big;
        }
    }

    bool empty() {
        return heap.empty();
    }

    void display() {
        if (heap.empty()) {
            cout << "priority queue empty\n";
            return;
        }

        cout << "heap: ";
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << "\n";
    }
};

int main() {

    PriorityQueue pq;
    int ch, x;

    while (true) {
        cout << "\n1. Insert\n2. Get max\n3. Delete max\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        if (ch == 5) break;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                pq.push(x);
                break;

            case 2:
                x = pq.top();
                if (x != -1)
                    cout << "Max element: " << x << "\n";
                break;

            case 3:
                pq.pop();
                break;

            case 4:
                pq.display();
                break;

            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}