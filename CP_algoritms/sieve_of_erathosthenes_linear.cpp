#include<bits/stdc++.h>
using namespace std;

vector<int> prime(int n){
    int lp[n+1] = {0};
    vector<int> pr;

    for(int i = 2;i<=n;i++){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }

        for(int j = 0;j<pr.size() && 
        pr[j] <= lp[i] && i * pr[j] <= n;j++){
            lp[i*pr[j]] = pr[j];
        }
    }
    return pr;
}
int main(){
    int t;
    
}