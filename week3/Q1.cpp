#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int &comparisons, int &shifts) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        shifts++;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            
            shifts++;
            comparisons++;
        }
        
        arr[j + 1] = key;
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
        int shifts = 0;
        
        insertionSort(arr, n, comparisons, shifts);
        
        cout << "Sorted array: ";
        printArray(arr, n);
        cout << "Total number of comparisons: " << comparisons << endl;
        cout << "Total number of shifts: " << shifts << endl;
        
        delete[] arr; // Deallocate memory
    }
    
    return 0;
}
