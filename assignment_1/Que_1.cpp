#include <iostream>
using namespace std;

int arr[100];
int n = 0;

void Create() {
    cout << "Enter size of Array: ";
    cin >> n;
    cout << "Enter elements of Array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void Display() {
    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Insert(int index, int element) {
    for (int i = n - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    n++;
}

void Delete(int index) {
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void LinearSearch(int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n-- MENU --\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Create();
        } 
        else if (choice == 2) {
            Display();
        } 
        else if (choice == 3) { 
            int index, element;
            cout << "Enter index to insert at (0 to " << n << "): ";
            cin >> index;
            if (index < 0 || index > n) {
                cout << "Invalid index.\n";
                continue;
            }
            cout << "Enter element to insert: ";
            cin >> element;
            Insert(index, element);
            cout << "Element inserted.\n";
        } 
        else if (choice == 4) {
            int index;
            cout << "Enter index to delete (0 to " << n - 1 << "): ";
            cin >> index;
            if (index < 0 || index >= n) {
                cout << "Invalid index.\n";
                continue;
            }
            Delete(index);
            cout << "Element deleted.\n";
        } 
        else if (choice == 5) {
            int key;
            cout << "Enter element to search: ";
            cin >> key;
            LinearSearch(key);
        } 
        else if (choice == 6) {
            cout << "Exiting program.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
