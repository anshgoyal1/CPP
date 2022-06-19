#include<bits/stdc++.h>
using namespace std;
#define ll long long int

unsigned ll countSetBits(unsigned ll n) 
{ 
    unsigned ll count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 

void bucket_sort(vector<ll> a){
    ll n = a.size();
    vector<vector<ll>> bucket_array(100);

    for(int i = 0;i<n;i++){
        bucket_array[countSetBits(a[i])].push_back(a[i]);
    }
    
    for(int i = 0;i<100;i++){
        sort(bucket_array[i].begin(),bucket_array[i].end());
    }

    vector<unsigned ll> res(n);
     int j=0;
     for(int i=0; i<100; i++){
         if(bucket_array[i].size()>0){
           for(int k=0;k<bucket_array[i].size();k++){
             res[j]=bucket_array[i][k];
             j++;
             if(k==bucket_array[i].size()-1){
             cout<<bucket_array[i][k];
             }
             else{
                  cout<<bucket_array[i][k]<<" ";
             }
         }
         cout<<"\n";  
         }
     }
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    bucket_sort(a);
}