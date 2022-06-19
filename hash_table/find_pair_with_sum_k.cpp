#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,k;
    cin >> n >> k;
    unordered_map<ll,ll> m;
    ll x;
    for(int i = 0;i<n;i++){
        cin >> x;
        m[x] = i;
    }

    for(auto it: m){
        ll ele = it.first;
        ll index = it.second;
        ll se = k - ele;
        auto sec = m.find(se);
        if(sec != m.end()){
            if(index >sec->second){
                cout << sec->second << " " << index;
            }else if(index < sec->second){
                cout << index << " " << sec->second;
            }
        }
    }
}