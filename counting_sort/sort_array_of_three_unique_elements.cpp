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
#define ull unsigned long long int 
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

void count_sort(ll arr[],ll output_array[],int n,ll max){
    ll count[max+1] = {0};

    for(int i = 0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i = 1;i<=max;i++){
        count[i] = count[i] + count[i-1];
    }

    for(int j= n-1;j>=0;j--){
        output_array[count[arr[j]]-1] = arr[j];
        count[arr[j]]--;
    }
}

 void solve(){
	ll n;
    cin >> n;
    ll arr[n];
    ll m = INT_MIN;
    rep(i,0,n){
        cin >> arr[i];
        m = max(arr[i],m);
    }
    sort(arr,arr+n);
    // ll output_arrray[n];
    // count_sort(arr,output_arrray,n,m);
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
 }
 
int main(){
	FAST;
	// int t;
	// cin >> t;
	// while(t--)
	solve();
	// TIME;
}