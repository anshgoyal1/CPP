#include<bits/stdc++.h>
using namespace std;
int getFirstElement(long long a[], int N, 
                    int K, int M) 
{ 
    // The array comes to original state 
    // after N rotations 
    K %= N; 
    int index; 
  
    // If K is greater or equal to M 
    if (K >= M) 
  
        // Mth element after k right 
        // rotations is (N-K)+(M-1) th 
        // element of the array 
        index = (N - K) + (M - 1); 
  
    // Otherwise 
    else
  
        // (M - K - 1) th element 
        // of the array 
        index = (M - K - 1); 
  
    int result = a[index]; 
  
    // Return the result 
    return result; 
} 
int main(){
    int n,m,k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }

    long long b[m];
    for(int i = 0;i<m;i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    long long x = a[k-1];

    cout << getFirstElement(b,m,x,k);
}