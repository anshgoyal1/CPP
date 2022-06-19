#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define ll long long
#define pb push_back
#define mii         map<ll,ll>
#define msi         map<string,ll>
#define mis         map<ll, string>
#define rep(i,a,b)    for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--)
#define trav(a, x)     for(auto& a : x)
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pair<ll, ll>>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define max(a,b)    (a>b?a:b)
#define min(a,b)    (a<b?a:b)

/*    For Debugging    */
#define DEBUG         cerr<<"\n>>>I'm Here<<<\n"<<endl;
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl;
#define what_iss(x)  cerr << #x << " = " << x << endl;
#define what_is(x)  cerr << #x << " = " << x << " ";

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define TIME        cerr << "\nTime elapsed: " << setprecision(5) <<1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
#define DECIMAL(n)  cout << fixed ; cout << setprecision(n);
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
#define PI 3.141592653589793
#define N  100005
 
ll find_cross_sum(vector<ll> a,ll low,ll mid,ll high){
    ll left_Sum = LLONG_MIN;
    ll sum = 0;
    for(ll i = mid;i>=low;i--){
        if(a[i] < 0){
            break;
        }
        sum += a[i];
        left_Sum = max(left_Sum,sum);
    }

    ll right_sum = LLONG_MIN;
    ll sum2 = 0;
    rep(i,mid+1,high+1){
        if(a[i] < 0){
            break;
        }
        sum2 += a[i];
        right_sum = max(right_sum,sum2);
    }
    return (left_Sum + right_sum);
}

ll max_non_negative_sum(vector<ll> a,ll low,ll high){
    if(high == low){
        return a[low];
    }else{
        ll mid = (high + low)/2;
        ll left_sum = max_non_negative_sum(a,low,mid);
        ll right_sum = max_non_negative_sum(a,mid+1,high);
        ll cross_sum = find_cross_sum(a,low,mid,high);

        return max(left_sum,max(right_sum,cross_sum));
    }
}
int main(){
	FAST;
	ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n){
        cin >> a[i];
    }

    ll max = max_non_negative_sum(a,0,n);
    cout << max << endl;
}
