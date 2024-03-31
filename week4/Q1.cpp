#include <iostream>
using namespace std;

int merge(int arr[], int left, int mid, int right) {
    int comparisons = 0;
    int inversions = 0;
    
    int left_size = mid - left + 1;
    int right_size = right - mid;
    
    int* left_array = new int[left_size];
    int* right_array = new int[right_size];
    
    for (int i = 0; i < left_size; i++)
        left_array[i] = arr[left + i];
    for (int j = 0; j < right_size; j++)
        right_array[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < left_size && j < right_size) {
        if (left_array[i] <= right_array[j]) {
            arr[k] = left_array[i];
            i++;
        } else {
            arr[k] = right_array[j];
            j++;
            inversions += mid - left + 1 - i;
        }
        k++;
        comparisons++;
    }
    
    while (i < left_size) {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    
    while (j < right_size) {
        arr[k] = right_array[j];
        j++;
        k++;
    }
    
    delete[] left_array;
    delete[] right_array;
    
    return comparisons;
}

int merge_sort(int arr[], int left, int right) {
    int comparisons = 0;
    
    if (left < right) {
        int mid = left + (right - left) / 2;
        comparisons += merge_sort(arr, left, mid);
        comparisons += merge_sort(arr, mid + 1, right);
        comparisons += merge(arr, left, mid, right);
    }
    
    return comparisons;
}

void sort_and_count(int arr[], int n) {
    int comparisons = merge_sort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Comparisons = " << comparisons << endl;
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int n;
        cout << "Enter the size of array: ";
        cin >> n;
        
        int *arr = new int[n];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        sort_and_count(arr, n);
        
        delete[] arr;
    }
    
    return 0;
}
