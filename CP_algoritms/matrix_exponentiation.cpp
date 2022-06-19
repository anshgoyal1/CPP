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

void multiply(int a[3][3],int b[3][3]){
    int mul[3][3];
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            mul[i][j] = 0; 
            for (int k = 0; k < 3; k++) 
                mul[i][j] += a[i][k]*b[k][j]; 
        }
    }
    for(int i= 0;i<3;i++){
        for(int j= 0;j<3;j++){
            a[i][j] = mul[i][j];
        }
    }
}

int power(int F[3][3],int n){
    int M[3][3] = {{1,1,1},{1,0,0},{0,1,0}};

    if(n == 1){
        return F[0][0] + F[0][1];
    }

    power(F,n/2);
    multiply(F,M);

    return F[0][0] + F[0][1];
}

int findNthTerm(int n){
    int F[3][3] = {{1,1,1},{1,0,0},{0,1,0}};

    if(n == 0)
    return 0;
    if(n == 1 || n == 2)
    return 1;

    return power(F,n-2);
}

 void solve(){
	ll n;
    cin >> n;

    int k = findNthTerm(0);
    int i = 0;
    bool isTrue = false;
    while(k <= n){
        k = findNthTerm(i);
        if(n == k){
            isTrue = true;
            break;
        }
        i++;
    }
    if(isTrue){
        cout  << "IsFibo" << endl;
    }else{
        cout << "IsNotFibo" << endl;
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
