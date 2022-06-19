#include<bits/stdc++.h>
using namespace std;
int m = 0;

bool compare(long long a,long long b){
    int x = a % m;
    int y = b % m;
    if(x == y){
        if(a % 2 == 0 && b % 2 !=0){
            if(a > 0 && b > 0){
                return a < b;
            }else{
                return a > b;
            }
        }else if(a % 2 != 0 && b % 2 ==0){
            if(a > 0 && b > 0){
                return a > b;
            }else{
                return a < b;
            }
        }else if(a % 2 != 0 && b % 2!=0){
            if(a > 0 && b > 0){
                return a > b;
            }else{
                return a < b;
            }
        }else if(a % 2 == 0 && b % 2 ==0){
            if(a > 0 && b > 0){
                return a < b;
            }else{
                return a > b;
            }
        }
    }
    return x < y;
}

int main(){
    int n;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),compare);
    for(int i = 0;i<n;i++){
        cout <<  a[i] << " ";
    }
}