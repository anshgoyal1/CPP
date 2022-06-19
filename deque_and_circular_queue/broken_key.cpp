#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        int i = 0;
        deque<char> d;
        while(i < s.length()){
            if(s[i] != '<' || s[i] != '>'){
                d.push_back(s[i]);
            }else if(s[i] == '<'){
                i++;
                while(s[i] != '>'){
                    d.push_
                }
            }
        }
    }
}