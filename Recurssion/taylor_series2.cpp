#include <bits/stdc++.h>
using namespace std;

double e(int x,int n){
    static double s;
    if(n == 0)
    return s;
    
    s = 1 + x*s/n;
    return e(x,n-1);

}


int main(){
    int x = 3;
    cout << e(2,10);
    // fun2(x);
    return 0;
}