#include <iostream>
using namespace std;

int countPairsWithDifference(int arr[], int n, int key) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] - arr[j] == key || arr[j] - arr[i] == key)
                count++;
        }
    }
    
    return count;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        int key;
        cin >> key;
        
        int pairsCount = countPairsWithDifference(arr, n, key);
        
        cout << pairsCount << endl;
        
        delete[] arr; // Deallocate memory
    }
    
    return 0;
}
