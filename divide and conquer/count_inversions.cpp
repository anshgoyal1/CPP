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
 
int merge(vi a,int low,int mid,int high){
    vi temp(high - low);
    int i = low;
    int j = mid;
    int k = 0;
    int inv_count = 0;

    while(i < mid && j < high){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
            inv_count += mid - i+1;
        }
    }
    while (i <= mid - 1) 
        temp[k++] = a[i++]; 
  
    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= high) 
        temp[k++] = a[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = low; i <= high; i++) 
        a[i] = temp[i]; 
  
    return inv_count; 
}

int count(vi a,int low,int high){
    int inv_count = 0;
        int mid = (high + low) / 2;
        inv_count += count(a,low,mid);
        inv_count += count(a,mid + 1,high);

        inv_count+= merge(a,low,mid,high);
    return inv_count;
}
 
int main(){
	FAST;
	ll n;
    cin >> n;
    vi a(n);
    rep(i,0,n-1){
        cin >> a[i];
    }
    cout << count(a,0,n);
}
