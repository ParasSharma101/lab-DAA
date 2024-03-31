#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int &comparisons, int &swaps) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        
        swaps++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int comparisons = 0;
        int swaps = 0;
        
        selectionSort(arr, n, comparisons, swaps);
        
        cout << "Sorted array: ";
        printArray(arr, n);
        cout << "Total number of comparisons: " << comparisons << endl;
        cout << "Total number of swaps: " << swaps << endl;
        
        delete[] arr; // Deallocate memory
    }
    
    return 0;
}
