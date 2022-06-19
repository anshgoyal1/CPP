#include <bits/stdc++.h>
using namespace std;

/*This algoritm is used to calculate a power n in 
O(log(n)) time complexity*/
#define ll long long
long long powerIter(ll a,ll p){
    int result = 1;

    while(p > 0){
        if(p % 2 == 1){
            result *= a;
        }
        a *= a;
        p = p / 2;
    }

    return result;
}

ll powerRec(ll a,ll p){
    if(p == 0){
        return 1;
    }

    long long res = powerRec(a,p/2);
    if(p % 2 == 1){
        return res * res * a;
    }else{
        return res * res;
    }
}
int main(){
    cout << powerIter(2,3);
}