#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<ll> toArray(ll i){
    vector<ll> vec;
    while(i>0){
        ll x = i%10;
        vec.push_back(x);
        i = i/10;
    }
    reverse(vec.begin(),vec.end());
    return vec;
}


ll number(vector<ll> vec){
    ll len = vec.size() - 1;
    ll num = 0;
    for(auto &i : vec){
        num += i*pow(10,len);
        len -= 1;
    }
    return num;
}


int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(auto &i : arr)
        cin>>i;
    
    ll next, prev, k, x, y;
    vector<ll> vec, vec2, lis;
    for(auto &i : arr){
        k = i;
        vec = toArray(i);
        vec2 = toArray(k);
        
        next_permutation(vec.begin(),vec.end());
        prev_permutation(vec2.begin(),vec2.end());
        
        x = number(vec);
        y = number(vec2);
        
        lis.push_back(x-y);
    }
    cout<< *max_element(lis.begin(),lis.end());
}