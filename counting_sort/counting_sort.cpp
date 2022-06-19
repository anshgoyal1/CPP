#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin >> n;

    int a[n];
    int m = 0;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    map<int,int> freemap;
    for(auto i:a){
        freemap[i]++;
    }

    int i = 0;
    for(auto it:freemap){
        int val = it.first;
        int freq = it.second;

        for(int j = 0;j<freq;j++){
            a[i++] = val;
        }
    }
    for(auto i:a){
        cout << i << " ";
    }

}