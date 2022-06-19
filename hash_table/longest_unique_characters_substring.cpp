#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int len = 0;
        for(int i = 0;i<s.length();i++){
            unordered_set<int> st;
            int j = i;
            while (st.count(s[j]) == 0 && j < s.length())
            {
                st.insert(s[j]);
                j++;
            }
            if(st.size() > len){
                len = st.size();
            }
        }
        cout << len << endl;
    }
}