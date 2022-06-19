#include <bits/stdc++.h>
using namespace std;

int fun1(int n){
    if(n>0){
        return n + fun1(n - 1);
    }else{
        return 0;
    }
    // cout << endl;
}


int main(){
    int x = 3;
    cout << fun1(x);
    // fun2(x);
    return 0;
}