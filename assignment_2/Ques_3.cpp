#include <iostream>

using namespace std;

int main() {
    
    int arr[5] = {1, 2, 3, 5, 6};
    int n = 5;

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << "Missing number is: " << i + 1 << endl;
            break;
        }
    }

    return 0;
}
