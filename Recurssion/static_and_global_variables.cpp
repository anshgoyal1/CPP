#include <bits/stdc++.h>
using namespace std;

//global variable
// int n = 0;
int add(int x){
    //static variable
    static int n = 0;

    if(x > 0){
        n++;
        return add(x - 1) + n;
    }
    return 0;
}

int main(){
    int x = 3;
    cout << add(x);
    return 0;
}