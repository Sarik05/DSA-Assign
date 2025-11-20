#include <iostream>
using namespace std;

void mergeArr(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[100], right[100];

    for (int i = 0; i < n1; i++)
        left[i] = a[l + i];

    for (int j = 0; j < n2; j++)
        right[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    mergeArr(a, l, m, r);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    return 0;
}