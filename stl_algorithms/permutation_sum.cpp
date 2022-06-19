#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,val;
    cin >> n >> val;

    vector<ll> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    auto pivot = upper_bound(a.begin(),a.end(),val);
    vector<ll> left(a.begin(),pivot);
    vector<ll> right(pivot+1,a.end());
    
    next_permutation(left.begin(),left.end());
    next_permutation(right.begin(),right.end());
    int i = 0;
    int j = 0;
    while(i < left.size() && j < right.size()){
        cout << left[i] + right[i] << " ";
        i++;
        j++;
     }

     while(i < left.size()){
         cout << left[i] <<  " ";
         i++;
     }
     while(j < right.size()){
         cout << right[j] << " ";
        j++;
     }

}