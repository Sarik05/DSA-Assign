#include <iostream>
using namespace std;

int main() {
    

    int arr[8] = {4, 5, 4, 6, 7, 8, 6, 9};  
    int n = 8;
    int ans = n;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                ans--;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
