#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,k;
    cin >> n >> k;
    ll x;
    priority_queue<ll> q;
    for(int i = 0;i<n;i++){
        cin >> x;
        q.push(x);
    }

    ll sum = 0;
    for(int i = 0;i<k;i++){
        x = q.top();
        sum += x;
        q.pop();
        q.push(x - 1);
    }
    cout << sum << endl;
}