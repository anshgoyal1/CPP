#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        string empty;
        getline(cin,empty,'\n');
        string S;
        getline(cin,S,'\n');
        int max = 0,i,j;
        for(i=0;i<S.length();i++){
            unordered_set<char> s;
            for(j=i;j<S.length();j++){
                s.insert(S[j]);
                if(s.size() == k+1){
                    break;
                }
            }
            int length = j-i;
            if(length > max){
                max = length;
            }
        }
        cout << max <<"\n";
    }
}