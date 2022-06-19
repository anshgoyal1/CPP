#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long a[n];
        for(long long i = 0;i<n;i++){
            cin >> a[i];
        }
        unordered_set<long long> b(a,a+n);
        long long s = b.size();

        cout << s * (s-1)/2 << endl;
    }
}