#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> s;
        int x;
        for(int i = 0;i<n;i++){
            cin >> x;
            s.insert(x);
        }

        int streak = 0;
        for(auto i: s){
            if(s.find(i - 1) == s.end()){
                int curr_val = i;
                int curr_len = 0;
                while(s.find(curr_val) != s.end()){
                    curr_val++;
                    curr_len++;
                }
                streak = max(streak,curr_len);
            }
        }
        cout << streak << endl;
    }
}