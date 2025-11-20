#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    bool swapped = true;

    for (int i = 0; i < n - 1 && swapped; i++) {
        swapped = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[100];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bubbleSort(a, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}