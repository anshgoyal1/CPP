#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isodd(ll a){
    return (a % 2 == 1);
}
int main(){
    ll n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }    
    vector<int> b(n);
    for(int i = 0;i<n;i++){
        cin >> b[i];
    }

    vector<ll> c(n);
    for(int i = 0;i<n;i++){
        c[i] = a[i] * b[i];
    }

    replace_if(c.begin(),c.end(),isodd,8);
    vector<ll> d(n);
    for(int i = 0;i<n;i++){
        // cout << c[i] << " ";
        d[i] = a[i] * c[i];
    }

    ll val;
    cin >> val;

    sort(d.begin(),d.end());

    cout << *upper_bound(d.begin(),d.end(),val) << endl; 
}