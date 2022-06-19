#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int lcs(string a,string b,int m,int n){
    if(m == 0 || n == 0){
        return 0;
    }
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    if(a[m - 1] == b[n - 1]){
        return dp[m][n] = 1 + lcs(a,b,m - 1,n - 1);
    }
    return dp[m][n] = max(lcs(a,b,m - 1,n) ,lcs(a,b,m,n - 1));
}
int main(){
    string a,b;
    cin>> a >> b;
    int n = a.length();
    int m = b.length();
    memset(dp,-1,sizeof(dp));
    cout << lcs(a,b,n ,m );
    return 0;
}