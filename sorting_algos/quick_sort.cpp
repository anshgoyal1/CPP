#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int low,int high){
    int pivot = a[high - 1];
    int i = low - 1;
    int j = low;
    while (j < high)
    {
        if(a[j] < pivot){
            i++;
            swap(a[i],a[j]);
        }
        
            j++;
        
    }
    swap(a[i+1],a[high - 1]);
    return i + 1;
}

void quickSort(int a[],int low,int high){
    if(low < high){
        int pivot = partition(a,low,high);
        quickSort(a,low,pivot-1);
        quickSort(a,pivot+1,high);
    }
}
int main(){
    int a[] = {4,5,2,8,9};
    quickSort(a,0,5);
    for(int i = 0;i<5;i++){
        cout << a[i] << " ";
    }
}