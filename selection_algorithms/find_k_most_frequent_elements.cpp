#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a1,pair<int,int> a2){
    return a1.second > a2.second;
}

int main(){
    long long n,k;
    cin >> n >> k;
    unordered_map<int ,int> map;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        map[x]++;
    }

    vector<pair<int,int>> A(map.begin(),map.end());
    sort(A.begin(),A.end(),compare);
    auto itr = A.begin();
    int sum = 0;
    while(k--){
        sum += itr->first;
        itr++;
    }

    cout << sum << endl;
}