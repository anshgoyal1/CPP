#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,x1,x2;
    cin >> n >> x1 >> x2;

    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    for(int i = x1-1;i<x2;i++){
        sum += v[i];
    }
    cout << sum;
}

