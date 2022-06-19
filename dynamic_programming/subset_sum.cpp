#include <bits/stdc++.h>
using namespace std;

bool dp[1000][1000];

bool subsetSum(vector<int> arr,int n,int sum){
    if(sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }

    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    if(arr[n - 1] > sum){
        return dp[n][sum] = subsetSum(arr,n-1,sum);
    }
    return dp[n][sum] = subsetSum(arr,n-1,sum - arr[n - 1])
     || subsetSum(arr,n - 1,sum);
}
int main(){

}