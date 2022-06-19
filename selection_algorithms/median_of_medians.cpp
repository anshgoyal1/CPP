#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int l,int r,int x){
    int i;
    for(i = l;i<r;i++){
        if(a[i] == x){
            break;
        }
    }
    swap(a[i],a[r]);

    i = l;
    for(int j = l;j<r;j++){
        if(a[j] <= x){
            swap(a[i],a[j]);
            i++;
        }
    }

    swap(a[i],a[r]);
    return i;
}

int findMedian(int a[],int n){
    sort(a,a+n);
    return a[n/2];
}

int kthSmallest(int arr[],int l,int r,int k){
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; // Number of elements in arr[l..r] 
  
        // Divide arr[] in groups of size 5, calculate median 
        // of every group and store it in median[] array. 
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n) //For last group with less than 5 elements 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        // Find median of all medians using recursive call. 
        // If median[] has only one element, then no need 
        // of recursive call 
        int medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        // Partition the array around a random element and 
        // get position of pivot element in sorted array 
        int pos = partition(arr, l, r, medOfMed); 
  
        // If position is same as k 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  // If position is more, recur for left 
            return kthSmallest(arr, l, pos-1, k); 
  
        // Else recur for right subarray 
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    // If k is more than number of elements in array 
    return INT_MAX; 
}
int main(){
    int arr[] = {12, 3, 5, 7, 4, 19, 26}; 
    int n = sizeof(arr)/sizeof(arr[0]), k = 3; 
    cout << "K'th smallest element is "
         << kthSmallest(arr, 0, n-1, k); 
    return 0; 
}