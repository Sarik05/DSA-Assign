#include <iostream>
using namespace std;

void inputMatrix(int arr[][10], int rows, int columns) {
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> arr[i][j];
        }
    }
}

void displayMatrix(int arr[][10], int rows, int columns) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void sumRows(int arr[][10], int rows, int columns) {
    cout << "Sum of each row:" << endl;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < columns; j++) {
            sum += arr[i][j];
        }
        cout << "Row " << i + 1 << ": " << sum << endl;
    }
}

void sumColumns(int arr[][10], int rows, int columns) {
    cout << "Sum of each column:" << endl;
    for (int j = 0; j < columns; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += arr[i][j];
        }
        cout << "Column " << j + 1 << ": " << sum << endl;
    }
}

int main() {
    int rows, columns;
    int arr[10][10];

    cout << "Enter number of rows (max 10): ";
    cin >> rows;
    cout << "Enter number of columns (max 10): ";
    cin >> columns;

    if (rows <= 0 || rows > 10 || columns <= 0 || columns > 10) {
        cout << "Invalid input size. Please enter rows and columns between 1 and 10." << endl;
        return 1;
    }

    inputMatrix(arr, rows, columns);
    displayMatrix(arr, rows, columns);
    sumRows(arr, rows, columns);
    sumColumns(arr, rows, columns);

    return 0;
}
