#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,q;
    cin >> n >> q;
    deque<ll> d;
    ll x;
    for(int i = 0;i<n;i++){
        cin >> x;
        d.push_back(x);
    }
    vector<ll> Q(q);
    for(int i = 0;i<q;i++){
        cin >> Q[i];
    }
    int ma = *max_element(Q.begin(),Q.end());
    vector<pair<ll,ll>> v;
    for(int i = 0;i<ma;i++){
            ll a = d.front(); d.pop_front();
            ll b = d.front(); d.pop_front();

            if(a > b){
                d.push_front(a);
                d.push_back(b);
            }
            else{
                d.push_front(b);
                d.push_back(a);
            }
            v.push_back(make_pair(d[0],d[1]));
    }
    for(int i = 0;i<q;i++){
        cout << v[Q[i] - 1].first << " " << v[Q[i] - 1].second << endl;
    }
}