#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i + 2;

    if(left < n && a[largest] < a[left]){
        largest = left;
    }
    if(right < n && a[largest] < a[right]){
        largest = right;
    }
    if(largest != i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}

void heap_sort(int a[],int n){
    for(int i = (n)/2 - 1;i>=0;i--){
        heapify(a,n,i);
    }

    for(int i = n - 1;i>=0;i--){
        swap(a[i],a[0]);

        heapify(a,i,0);
    }
}
int main(){

}