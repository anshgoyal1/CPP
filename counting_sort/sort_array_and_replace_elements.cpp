#include<bits/stdc++.h>
using namespace std;
#define ll long long

void count_sort(ll a[],ll out[],ll n,ll m){
    ll count[m + 1] = {0};

    for(int i = 0;i<n;i++){
        count[a[i]]++;
    }

    for(int i = 1;i<=m;i++){
        count[i] = count[i]+ count[i-1];
    }

    for(int i = n-1;i>=0;i--){
        out[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
}
int main(){
    ll n;
    cin>> n;
    ll a[n];
    ll m = 0;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        m = max(m,a[i]);
    }

    multiset<ll> re(a,a+n/2);
    ll out[n];
    count_sort(a,out,n,m);
    auto it = re.begin();
    for(int i = 0;i<n;i++){
        if(out[i] == *it && it != re.end()){
            out[i] = -1;
            it++;
        }
    }
    for(int i = 0;i<n;i++){
        cout << out[i] << " ";
    }
}