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

    while(k>1){
        q.pop();
        k--;
    }
    cout << q.top() << endl;
}