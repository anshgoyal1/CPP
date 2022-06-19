#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin >> t;
    while(t--){
        long long k;
        cin >> k;

        bitset<64> num(k);
        bitset<64> bit1;
        bitset<64> bit2;
        int ones = num.count();
        int p = 0;
        for(int i = 0;i<64;i++){
            if(p == ones){
                break;
            }
            if(num[i] && p % 2 == 1){
                p++;
                bit1.set(i,1);
            }
            else if(num[i] && p % 2 == 0){
                bit2.set(i,1);
                p++;
            }  
        }

        cout << bit2.to_ulong() << " " << bit1.to_ulong() << endl;
    }
}