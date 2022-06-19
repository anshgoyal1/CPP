#include <bits/stdc++.h>
using namespace std;

int dac_max(int a[],int index,int l){
    int max;
    if(index >= l - 2){
        if(a[index] > a[index + 1]){
            return a[index];
        }else{
            return a[index + 1];
        }
    }

    max = dac_max(a,index + 1,l);

    if(a[index] > max){
        return a[index];
    }else{
        return max;
    }
}

int dac_min(int a[],int index,int l){
    int min;
    if(index >= l - 2){
        if(a[index] < a[index + 1]){
            return a[index];
        }else{
            return a[index + 1];
        }
    }

    min = dac_min(a,index + 1,l);

    if(a[index] < min){
        return a[index];
    }else{
        return min;
    }
}
int main(){
    int min, max, N;
 
    // Initializing the array
    int a[7] = { 70, 250, 50, 80, 140, 12, 14 };
 
    // recursion - DAC_Max function called
    max = dac_max(a, 0, 7);
 
    // recursion - DAC_Max function called
    min = dac_min(a, 0, 7);
    printf("The minimum number in a given array is : %d\n", min);
    printf("The maximum number in a given array is : %d", max);
    return 0;
}