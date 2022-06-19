#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        unordered_map<char,int> m;
        for(int i = 0;i<s.length();i++){
            m[s[i]]++;
        }

        // int flag = 0;
        unordered_set<char> st;
        for(auto it:m){
            if(it.second % 2 != 0){
                st.insert(it.first);
            }
        }
        if(st.size() == 1 || st.size() == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}