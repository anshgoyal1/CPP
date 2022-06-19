#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        priority_queue<ll,vector<ll>,greater<ll>> p;
        ll x;
        for(int i = 0;i<n;i++){
            cin >> x;
            p.push(x);
        }

        ll sum = 0;
        while(p.size() != 1){
            ll x = p.top();
            p.pop();
            ll y = p.top();
            p.pop();

            sum += x + y;
            p.push(y + x);
        }
        cout << sum << endl;
    }
    
}