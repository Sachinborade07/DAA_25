#include <iostream>
using namespace std;

void moveZeroesToEnd(int arr[], int size) {
    int count = 0; 
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            count++;
        }
    }
    while (count < size) {
        arr[count] = 0;
        count++;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    printArray(arr, size);
    moveZeroesToEnd(arr, size);
    cout << "Array after moving zeroes to the end: ";
    printArray(arr, size);
    return 0;
}
