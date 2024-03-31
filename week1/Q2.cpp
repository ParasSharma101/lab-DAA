#include <iostream>

using namespace std;

int binary_search(int arr[], int low, int high, int key, int *comparisons) {
    while (low <= high) {
        (*comparisons)++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

int main() {
    int size, key;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the sorted array elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;
    int comparisons = 0;
    int result = binary_search(arr, 0, size - 1, key, &comparisons);
    if (result) {
        cout << key << " is present in the array.\n";
    } else {
        cout << key << " is not present in the array.\n";
    }
    cout << "Total comparisons: " << comparisons << "\n";
    return 0;
}