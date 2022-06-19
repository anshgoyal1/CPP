#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> a(27,0);
    for(int i = 0;i<s.length();i++){
        a[s[i] - 'a' + 1]++;
    }
    // cout << s.length() << endl;
    make_heap(a.begin(),a.end());
    for(int i = 0;i<n;i++){
        int k = a.front();
        pop_heap(a.begin(),a.end());
        a.pop_back();
        a.push_back(k-1);
        push_heap(a.begin(),a.end());
    }
    long long ans = 0;
    while(a.front() != 0){
        // cout << a.front() << endl;
        ans += pow(a.front(),2);
        pop_heap(a.begin(),a.end());
        a.pop_back();
    }

    cout << ans << endl;
}