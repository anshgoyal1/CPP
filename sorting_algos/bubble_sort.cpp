#include<bits/stdc++.h>
using namespace std;

void bubble_Sort(vector<int>& a,int n){
    for(int i = 0;i<n - 1;i++){
        for(int j = 0;j<n - i - 1;j++){
            if(a[j] > a[j+ 1]){
                swap(a[j],a[j + 1]);
            }
        }
    }
}
int main(){
    vector<int> a = {7,3,5,1,8,2};
    bubble_Sort(a,6);

    for(auto it:a){
        cout << it << " ";
    }
}