#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;

    vector<vector<int>> a(k);
    for(int i = 0;i<k;i++){
        int x;
        cin >> x;
        for(int j = 0;j<x;j++){
            int temp;
            cin >> temp;
            a[i].push_back(temp);
        }
    }
    
    map<int,int> m;
    for(int i = 0;i<k;i++){
        m[a[i][0]]++;
        for(int j = 1;j<a[i].size();j++){
            if(a[i][j] != a[i][j-1]){
                m[a[i][j]]++;
            }
        }
    }
    for(auto i: m){
        if(i.second == k){
            cout << i.first << " ";
        }
    }
}