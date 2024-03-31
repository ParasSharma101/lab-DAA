#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

const char* checkDuplicates(int arr[], int n) {
    // Sort the array
    qsort(arr, n, sizeof(int), compare);
    
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            return "YES";
        }
    }
    
    return "NO";
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
        
        cout << checkDuplicates(arr, n) << endl;
        
        delete[] arr; // Deallocate memory
    }
    
    return 0;
}
