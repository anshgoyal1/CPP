#include<bits/stdc++.h>
using namespace std;

#define max 1000000

int dp[2000][2000];

int sum_subarray(int a[],int n,int sum){
    if(sum == 0){
        return 1;
    }

    if(n == 0){
        return 0;
    }
    if(dp[n- 1][sum] != -1){
        return dp[n - 1][sum];
    }

    if(sum < a[n-1]){
        return dp[n - 1][sum] = sum_subarray(a,n-1,sum);
    }else{
        return dp[n - 1][sum] = sum_subarray(a,n-1,sum - a[n-1]) || sum_subarray(a,n-1,sum);
    }
}

bool isSubsetSum(int set[],int n,int sum){
    bool dp[n+1][sum + 1];
    for(int i = 0;i<=sum;i++){
        dp[0][i] = false;
    }

    for(int j = 0;j<=n;j++){
        dp[j][0] = true;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=sum;j++){
            if(j < set[i - 1]){
                dp[i][j] = dp[i-1][j];
            }
            if(j >= set[i - 1]){
                dp[i][j] = dp[i-1][j] || dp[i-1][j - set[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n = 5;
    int a[] = {1,5,3,7,4};
    int sum = 12;

    cout << isSubsetSum(a,n,sum);
}