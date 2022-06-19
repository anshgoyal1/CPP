#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& a,int n){
   int key;
   for(int i = 1;i<n;i++){
       key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
   } 
}
int main(){
    vector<int> a = {7,3,5,1,8,2};
    insertion_sort(a,6);

    for(auto it:a){
        cout << it << " ";
    }
}