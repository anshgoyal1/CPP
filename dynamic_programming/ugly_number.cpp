#include <bits/stdc++.h>
using namespace std;

int getNthUglyNumber(int n){
    int ugly[n];
    int i2,i3,i5,next_ugly;
    i2 = i3 = i5 = 0;

    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;

    ugly[0] = 1;

    for(int i= 1;i<n;i++){
        next_ugly = min(next_multiple_of_2,
        min(next_multiple_of_3,next_multiple_of_5));

        ugly[i] = next_ugly;

        if(next_ugly == next_multiple_of_2){
            i2++;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if(next_ugly == next_multiple_of_3){
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if(next_ugly == next_multiple_of_5){
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }
    return next_ugly;
}

int main(){
    int n = 150;
    cout << getNthUglyNumber(n) << endl;
}