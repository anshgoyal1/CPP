#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        deque<char> d;
        for(int i = 0;i<s.length();i++){
            if(s[i] != '<'){
                d.push_back(s[i]);
            }else{
                int freq = 0;
                while(i < s.length() && s[i] == '<'){
                    freq++;
                    i++;
                }
                while(freq-- && !d.empty()){
                    d.pop_back();
                }
                i-=1;
            }
        }
        string result = "";
        while(!d.empty()){
            result += d.front();
            d.pop_front();
        }

        cout << result << endl;
    }
}