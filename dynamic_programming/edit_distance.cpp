#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int edit_distance(string a,string b,int n,int m){
    if(n == 0){
        return m;
    }
    if(m == 0){
        return n;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    if(a[n - 1] == b[m - 1]){
        return dp[n][m] = edit_distance(a,b,n - 1,m - 1);
    }

    return dp[n][m] = 1 + min(edit_distance(a,b,n - 1,m),
    min(edit_distance(a,b,n,m-1),edit_distance(a,b,n-1,m-1)));
}

int main(){
    string a,b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    memset(dp,-1,sizeof(dp));

    cout << edit_distance(a,b,n,m) << endl;
    return 0;
}