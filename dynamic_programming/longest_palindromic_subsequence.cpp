#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int longest_palindromic_subsequence(string s,string r,int i,int j,int n){
    if(i == n || j == n){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i] == r[j]){
        return dp[i][j] = 1 + longest_palindromic_subsequence(s,r,i + 1,j + 1,n);
    }
    return max(longest_palindromic_subsequence(s,r,i + 1,j,n),
    longest_palindromic_subsequence(s,r,i,j + 1,n));
}

int main(){
    string s;
    cin >> s;
    string r = s;
    reverse(r.begin(),r.end());
    memset(dp,-1,sizeof(dp));
    cout << longest_palindromic_subsequence(s,r,0,0,s.length());
}