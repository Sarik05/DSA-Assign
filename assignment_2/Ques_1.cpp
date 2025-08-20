#include <iostream>
#include <string>

using namespace std;

int main() {
    int numbers[] = {11, 23, 35, 42, 57, 63, 74, 85,  95}; 
    int length = sizeof(numbers) / sizeof(numbers[0]);
    
    int target;
    cout << "Enter a number to search for: ";
    cin >> target;

    int low = 0;
    int high = length - 1;
    bool Found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (numbers[mid] == target) {
            cout << "Number found at position " << mid << "." << endl;
            Found = true;
            break;
        } 
        if (target < numbers[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (!Found) {
        cout << "Number not present in the list." << endl;
    }

    return 1;
}
