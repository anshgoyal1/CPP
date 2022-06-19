#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool pred(ll a){
    return a > 0;
}

bool odd(ll a){
    return a%2 == 1;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    
    ll result = 0;

    int max_ele = *max_element(a.begin(),a.end());
    int count_odd = count_if(a.begin(),a.end(),odd);

    if(count_odd >= max_ele){
        cout << max_ele;
        return 0;
    }

    result = count_odd;
    max_ele -= count_odd;
    result += max_ele/2;

    if(max_ele % 2){
        result++;
    }

    cout << result << endl;
 }