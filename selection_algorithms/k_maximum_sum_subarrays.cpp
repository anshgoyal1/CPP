#include<bits/stdc++.h>
using namespace std;
#define ll long long

void k_max_sum_subarray(ll a[],int k,int n){
    for(int c = 0;c < k;c++){
        ll max_sum = INT_MIN;
        ll curr_sum = 0;
        ll start = 0,end = 0,s = 0;

        for(int i = 0;i<n;i++){
            curr_sum += a[i];
            if(max_sum < curr_sum){
                max_sum = curr_sum;
                start = s;
                end = i;
            }

            if(curr_sum <= 0){
                curr_sum = 0;
                s = i + 1;
            }
        }

        for(int l = start;l <= end;l++){
            a[l] = INT_MIN;
        }

        if(max_sum < 0){
            cout << 0 << " ";
        }else{
            cout << max_sum << " ";
        }
    }
    cout << endl;
}
int main(){
    long long n,k;
    cin >> n >> k;
    ll a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    k_max_sum_subarray(a,k,n);
}