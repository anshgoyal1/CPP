#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    int mat[m][n];
    map<int,int> cnt;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    int i, j; 
  
    for (i = 0; i < m; i++) { 
  
        // Increment the count of first 
        // element of the row 
        cnt[mat[i][0]]++; 
  
        // Starting from the second element 
        // of the current row 
        for (j = 1; j < n; j++) { 
  
            // If current element is different from 
            // the previous element i.e. it is appearing 
            // for the first time in the current row 
            if (mat[i][j] != mat[i][j - 1]) 
                cnt[mat[i][j]]++; 
        } 
    } 
    bool is = false;
    for(auto it:cnt){
        if(it.second == m){
            is = true;
            cout << it.first << endl;
            break;
        }
    }
    if(!is){
        cout << -1;
    }
}