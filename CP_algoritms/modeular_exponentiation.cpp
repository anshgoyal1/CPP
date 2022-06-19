#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll modex(ll x,ll y,ll n){
    x %= n;
    ll result = 1;
    while(y > 0){
        if(y & 1){
            result = result * x % n;
        }
        x = x * x%n;
        y /= 2;
    }
    return result;
}
void solve(){
    ll x,y,n;
    cin >> x >> y >> n;
    cout << modex(x,y,n)  << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}