#include <iostream>
using namespace std;

int main() {
    

    int size = 5;
    int inversionCount = 0;
    int numbers[] = {4, 1, 3, 2, 5}; 

    for (int a = 0; a < size; a++) {
        for (int b = a + 1; b < size; b++) {
            if (numbers[a] > numbers[b]) {
                inversionCount++;
            }
        }
    }

    cout << "Total inversions: " << inversionCount << endl;

    return 0;
}
