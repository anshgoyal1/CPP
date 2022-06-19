#include<bits/stdc++.h>
using namespace std;
#define ll long long

void min_heapify(int a[],int m,int n){
    ll smallest = m;
    ll left = 2 * m + 1;
    ll right = 2 * m + 2;
    if(left < n && a[left] < a[smallest]){
        smallest = left;
    }
    if(right < n && a[right] < a[smallest]){
        smallest = right;
    }
    if(smallest != m){
        swap(a[m],a[smallest]);
        min_heapify(a,smallest,n);
    }

}

void build_min_heap(int a[],int n){
    for(int i = (n/2 - 1);i >=0;i--){
        min_heapify(a,i,n);
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    build_min_heap(A,n);

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
            cout << A[i] << " ";
        else
            cout << A[i];
    }
    return 0;
}