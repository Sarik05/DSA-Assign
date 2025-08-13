#include <iostream>
using namespace std;

void displayArray(int arr[], int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void removeDuplicates(int arr[], int &n) {
    if (n == 0) return;

    int i = 0; 

    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    n = i + 1; 
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements (sorted):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    removeDuplicates(arr, n);

    cout << "Array after removing duplicates:\n";
    displayArray(arr, n);

    return 0;
}
