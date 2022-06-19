#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n;
        cin >> n;
        string k[n];
        for(int i = 0;i<n;i++){
            cin >> k[i];
        }
        stable_sort(s.begin(),s.end());
        bool is = false;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                string h = k[i] + k[j];
                stable_sort(h.begin(),h.end());
                if(h == s){
                    is = true;
                    break;
                }
            }
        }
        if(is){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
}