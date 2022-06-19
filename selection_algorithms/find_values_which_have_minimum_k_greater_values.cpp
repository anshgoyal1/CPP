#include<iostream>
using namespace std;
#include<algorithm>
#include<unordered_set>
int main(){
    int n,k,i;
    cin >> n >> k;
    int arr[n],temp[n];
    for(i=0;i<n;i++){
        cin >> arr[i];
        temp[i] = arr[i];
    }
    sort(arr,arr+n);
    unordered_set<int> set;
    for(i=n-k;i<n;i++){
        set.insert(arr[i]);
    }
        for(i=0;i<n;i++){
        if(set.count(temp[i]) == 0){
            cout<< temp[i]<<" ";
        }
    }
    }

