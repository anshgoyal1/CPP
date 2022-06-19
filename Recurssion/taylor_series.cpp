#include <bits/stdc++.h>
using namespace std;

double e(int x,int n){
    static int f = 1;
    static int p = 1;
    double r;
    if(n == 0)
    return 1;
    else{
        r = e(x,n - 1);
        f = f*n;
        p = p*x;
        return r + (p/f);
    }

}


int main(){
    int x = 3;
    cout << e(2,2);
    // fun2(x);
    return 0;
}