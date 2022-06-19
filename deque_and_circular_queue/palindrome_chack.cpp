#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        deque<char> d(s.begin(),s.end());
        bool pal = true;
        while(d.size() > 1){
            if(d.front() != d.back()){
                pal = false;
                break;
            }
            d.pop_front();
            d.pop_back();
        }

        if(pal){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
}