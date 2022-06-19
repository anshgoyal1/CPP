#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool compare(pair<ll,ll> p1,pair<ll,ll> p2){
    return p1.first < p2.first;
}
int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll>> v;
    for(int i = 0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),compare);
    priority_queue<ll,vector<ll>,greater<ll>> p;
    p.push(v[0].second);
    for(int i = 1;i<n;i++){
        if(p.top() <= v[i].first){
            p.pop();
        }
        p.push(v[i].second);
    }
    cout << p.size();
}