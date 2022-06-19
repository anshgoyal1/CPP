#include<bits/stdc++.h>
using namespace std;

int dp[1000];

int numOfWays(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    return numOfWays(n - 1) + numOfWays(n - 2) + numOfWays(n - 3);
}

int main(){
    // int n;
    // cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << numOfWays(3) << endl;
}