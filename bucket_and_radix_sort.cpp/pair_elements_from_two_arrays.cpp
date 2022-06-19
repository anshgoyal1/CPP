#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(n);
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        for(int i = 0;i<m;i++){
            cin >> b[i];
            
        }

        bool is = true;
        for(int i = 0;i<n;i++){
            auto max_a = max_element(a.begin(),a.end());
            auto min_b = min_element(b.begin(),b.end());
            if(*max_a < *min_b){
                is = false;
                break;
            }
            a.erase(max_a);
            b.erase(min_b);
        }

        if(is){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
}