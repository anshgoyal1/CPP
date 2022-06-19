#include<bits/stdc++.h>
using namespace std;
#define ll long long
void heapify(ll a[],int m,int n){
    ll largest = m;
    ll left = 2 * m + 1;
    ll right = 2 * m + 2;

    if(left < n && a[left] > a[largest]){
        largest = left;
    }
    if(right < n && a[right] > a[largest]){
        largest = right;
    }

    if(largest != m){
        swap(a[largest],a[m]);
        heapify(a,largest,n);
    }
}

void build_heap(ll a[],int n){
    for(ll i = (n/2) - 1;i>=0;i--){
        heapify(a,i,n);
    }
}
int main(){
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    build_heap(a,n);

    for(int i =0;i<n;i++){
        cout << a[i] << " ";
    }
}