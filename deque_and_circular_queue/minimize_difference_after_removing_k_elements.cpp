#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    long long n,k;
    cin >> n >> k;

    deque<ll> d;
    ll a;
    for(int i = 0;i<n;i++){
        cin >> a;
        d.push_back(a);
    }
    deque<ll> diff;
    for(int i = 0;i<n-1;i++){
        diff.push_back(d[i+1] - d[i]);
    }
    for(int i = 0;i<k;i++){
        int m = *max_element(diff.begin(),diff.end());
        int left,right;
        for(int j = 0;j<diff.size();j++){
            if(diff[j] == m){
                left = j;
            }
        }
        for(int j = diff.size() - 1;j>=0;j--){
            if(diff[j] == m){
                right = j;
            }
        }
        if(left+1 <= diff.size() - right){
            d.pop_front();
            diff.pop_front();
        }else{
            d.pop_back();
            diff.pop_back();
        }
    }
    cout << *max_element(diff.begin(),diff.end());
}