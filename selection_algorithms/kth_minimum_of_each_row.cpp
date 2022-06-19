#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    
    
    vector<vector<long long>> a(m);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            long long x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    int t;
    cin >> t;
    while(t--){
        long long val,k;
        cin >> val >> k;
        int row;
        bool found = false;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(a[i][j] == val){
                    row = i;
                    found = true;
                    break;
                }
        }
    }
    

    if(found){
        sort(a[row].begin(),a[row].end());
        cout << a[row][k-1] << endl;
    }else{
        cout << -1 << endl;
    }
    }

    return 0; 
}