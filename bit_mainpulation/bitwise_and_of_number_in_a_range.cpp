#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin >> m  >> n;
    int k = m;
    for(int i = m+1;i<=n;i++){
        k = k & i;
    }

    cout << k << endl;
}