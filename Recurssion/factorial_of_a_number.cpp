#include <bits/stdc++.h>
using namespace std;

int fun1(int n){

    if(n == 0)
    return 1;

    return n * fun1(n - 1); 
}


int main(){
    int x = 5;
    cout << fun1(x);
    // fun2(x);
    return 0;
}