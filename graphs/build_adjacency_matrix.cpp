#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin >> n >> k;
    int adj[n][n] = {0};
    for(int i = 0;i<k;i++){
        int x,y;
        cin >> x >> y;

        adj[x][y] = 1;
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

}