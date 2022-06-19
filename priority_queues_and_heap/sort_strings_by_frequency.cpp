#include<bits/stdc++.h>
using namespace std;
bool comp(pair<char,int> a,pair<char,int> b){
    if(a.second == b.second){
       return a.first > b.first;
    }
    return a.second > b.second;
}
int main(){
    int n;
    cin >> n;

    while(n--){
        string s;
    cin >> s;
    long long a[26] = {0};
    for(int i = 0;i<s.length();i++){
        a[s[i] - 'a']++;
    }
    vector<pair<char,int>> v;
    for(int i = 0;i<26;i++){
        if(a[i] > 0){
            // cout << a[i] << " ";
            v.push_back(make_pair(i + 'a',a[i]));
        }
    }
    sort(v.begin(),v.end(),comp);

    for(int j = 0;j<v.size();j++){
        for(int i = 0;i<v[j].second;++i){
            cout << v[j].first;
        }
    }
    cout << endl;
    }
}