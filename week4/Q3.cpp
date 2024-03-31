#include <iostream>
#include <queue>
using namespace std;

int findKthSmallest(int arr[], int size, int k) {
    priority_queue<int> pq;

    // Insert the first K elements into the priority queue
    for (int i = 0; i < k; ++i) {
        pq.push(arr[i]);
    }

    // Insert the remaining elements while keeping the size of the priority queue <= K
    for (int i = k; i < size; ++i) {
        if (arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // The top element of the priority queue will be the Kth smallest element
    return pq.top();
}

int main() {
    int t;
    cout<<"Enter the number of test cases";
    cin>>t;
    while(t){
        cout<< "Enter the size";
        int size;
        cin>>size;
        int arr[size];
        cout<<"Enter the Elements";
        for(int i =0; i<size; i++){
            cin>>arr[i];
        }
        cout<<"Enter the value of K";
        int k;
        cin>>k;

        int kthSmallest = findKthSmallest(arr, size, k);
        std::cout << "The " << k << "th smallest element is: " << kthSmallest << std::endl;
        t--;
    }
    return 0;
}
