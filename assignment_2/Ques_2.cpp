#include <iostream>

using namespace std;

int main() {
    
    int data[5] = {4, 9, 3, 6, 1};
    int size = 5;

    
    for (int pass = 1; pass < size; pass++) {
        bool Sorted = true;

        
        for (int i = 0; i < size - pass; i++) {
            if (data[i] > data[i + 1]) {
                
                int tempVal = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tempVal;
                Sorted = false;
            }
        }

        
        if (Sorted) {
            break;
        }
    }

    
    for (int k = 0; k < size; k++) {
        cout << data[k] << " ";
    }

    return 0;
}
