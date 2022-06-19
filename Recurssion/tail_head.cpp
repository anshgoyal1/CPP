#include <bits/stdc++.h>
using namespace std;

void fun1(int n){
    if(n > 0){
        cout << n << " ";
        fun1(n - 1);
    }
    cout << endl;
}

void fun2(int n){
    if(n > 0){
        fun2(n - 1);
        cout << n << " ";
        
    }
    // cout << endl;
}

int main(){
    int x = 3;
    fun1(x);
    fun2(x);
    return 0;
}