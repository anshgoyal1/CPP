#include<bits/stdc++.h>
using namespace std;
#define ll long long

void count_sort(ll a[],ll n,ll exp){
    ll output[n];
    int i,count[10] = {0};

    for(i = 0;i<n;i++){
        count[(a[i]/exp) % 10]++;
    }

    for(i = 1;i<10;i++){
        count[i] += count[i-1];
    }

    for(i = n - 1;i>=0;i--){
        output[count[(a[i]/exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for(i = 0;i<n;i++){
        a[i] = output[i];
    }
}

void radix_sort(ll a[],ll n,ll m){
    for(ll exp = 1; m/exp > 0;exp *= 10){
        count_sort(a,n,exp);
    }
}

void print(ll arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll m = 0;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        m = max(m,a[i]);
    }

    radix_sort(a,n,m);
    print(a,n);
}