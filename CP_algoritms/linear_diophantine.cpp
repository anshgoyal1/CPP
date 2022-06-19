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

ll extended_gcd(ll a,ll b,ll &x0,ll &y0){
    if(b == 0){
        x0 = 1;
        y0 = 0;
        return a;
    }

    ll x1,y1;
    ll d = extended_gcd(b,a % b,x1,y1);
    x0 = y1;
    y0 = x1 - y1 *a/b;
    return d;
}

bool linear_diophantine(ll a,ll b,ll c,ll &x0,ll &y0,ll &g){
    g = extended_gcd(abs(a),abs(b),x0,y0);
    if(c % g){
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;

    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}

 void solve(){
	ll a,b,c;
    cin >> a >> b >> c;
    ll x,y,g;
    bool k = linear_diophantine(a,b,c,x,y,g);
    if(k){
        cout  << "Yes" << endl;
    }else{
    cout<< "No" << endl;
    }
 }
 
int main(){
	FAST;
	int t;
	cin >> t;
	while(t--)
	solve();
	// TIME;
}
