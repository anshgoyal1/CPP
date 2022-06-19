#include <bits/stdc++.h>
using namespace std;
int c[6][3];
int coef(int n,int k){
    if(k > n){
        return 0;
    }
    if(k == 0 || k == n){
        return 1;
    }

    if(c[n][k] != -1){
        return c[n][k];
    }
    c[n-1][k - 1] = coef(n - 1,k - 1);
    c[n - 1][k] = coef(n - 1,k);
    return c[n - 1][k - 1] + c[n - 1][k];
}
int main(){
    for(int i = 0;i<6;i++){
        for(int j = 0;j<3;j++){
            c[i][j] = -1;
        }
    }

    cout << coef(5,2) << endl;
}