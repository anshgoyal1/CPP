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

void bucket_sort(vector<double> &a){
    ll n = a.size();
    vector<vector<double>> bucket_array_positive(n);
    
    rep(i,0,n){
        bucket_array_positive[floor(a[i]/100000000)].push_back(a[i]);
    }

    rep(i,0,n){
        sort(all(bucket_array_positive[i]));
        
    }

    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < bucket_array_positive[i].size(); j++) 
            a[index++] = bucket_array_positive[i][j]; 
}

 void solve(){
	ll n;
    cin >> n;
    vector<double> apos;
    vector<double> aneg;
    rep(i,0,n){
        double x;
        cin >> x;
        if(x > 0){
            apos.push_back(x);
        }else{
            aneg.push_back(-x);
        }
    }

    bucket_sort(aneg);
    bucket_sort(apos);
    repr(i,0,aneg.size()){
        printf("%0.2f ",-aneg[i]);
    }
    rep(i,0,apos.size()){
        printf("%0.2f ", apos[i]);
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
