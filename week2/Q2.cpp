#include <iostream>
using namespace std;

void findIndices(int arr[], int n) {
    int found = 0;
    
    for (int k = n - 1; k >= 0; k--) {
        int i = 0, j = k - 1; 
        
        while (i < j) {
            if (arr[i] + arr[j] == arr[k]) {
                found = 1;
                cout << i+1 << " " << j+1 << " " << k+1 << endl; 
                break;
            } else if (arr[i] + arr[j] < arr[k]) {
                i++; 
            } else {
                j--; 
            }
        }
        
        if (found)
            break; 
    }
    
    if (!found)
        cout << "No such triplet exists" << endl; 
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
        
        findIndices(arr, n);
        
        delete[] arr; // Deallocate memory
    }
    
    return 0;
}
