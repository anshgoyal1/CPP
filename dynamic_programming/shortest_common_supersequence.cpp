#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int lcs(string s1,string s2,int m,int n){
    
    if(m == 0 || n == 0){
        return 0;
    }

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    if(s1[m - 1] == s2[n - 1]){
        return dp[m][n] = 1 + lcs(s1,s2,m-1,n-1);
    }
    return dp[m][n] = max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
}
int main(){
    memset(dp,-1,sizeof(dp));
    string s1,s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();

    int p = lcs(s1,s2,m,n);
    cout << m + n - p << endl;
}