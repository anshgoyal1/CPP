#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        unsigned int a;
        cin >> a;
        
        bitset<32> bit(a);

        bit.flip();
        cout << bit.to_ulong() << " ";
    }
}