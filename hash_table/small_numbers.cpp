#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    map<int,vector<int>> map;
    for(int i = 0;i<n;i++){
        map[a[i]].push_back(i);
    }

    int count = 0;
    auto itr = map.begin();
    for(int i = 0;i<map.size();++i){
        vector<int> map_val = itr->second;
        for(int j = 0;j<map_val.size();j++){
            a[map_val[j]] = count;
        }

        count += map_val.size();
        itr++;
    }

    for(int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
}