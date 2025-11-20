#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[100];

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    selectionSort(a, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}