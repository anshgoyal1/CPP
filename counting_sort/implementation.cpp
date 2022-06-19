#include<bits/stdc++.h>
using namespace std;

void count_sort(int arr[],int output_array[],int max){
    int count[max+1] = {0};

    for(int i = 0;i<7;i++){
        count[arr[i]]++;
    }
    for(int i = 1;i<=max;i++){
        count[i] = count[i] + count[i-1];
    }

    for(int j= 6;j>=0;j--){
        output_array[count[arr[j]]-1] = arr[j];
        count[arr[j]]--;
    }
}

int main(){
    int arr[] = {4,8,6,2,5,8,9};
    int n = 7;
    int max = 9;
    int output_array[n]; 
    count_sort(arr,output_array,max);
    for(int i = 0;i<n;i++){
        cout << output_array[i] << " ";
    }   
}