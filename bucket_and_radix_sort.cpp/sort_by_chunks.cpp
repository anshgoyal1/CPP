#include<bits/stdc++.h>
using namespace std;
#define ll long long
int get_chunk(ll n,long long int d){
    return ((n/d)%10)*100 + (((n*10)/d)%10)*10 + ((n*100)/d)%10;
}
void print_chunk(ll arr[],ll n){
    ll m = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > m ){
            m = arr[i];
        }
    }
    int digits = 0;
    while(m > 0){
        digits += 1;
        m = m / 10;
    }

    int itr;
    if(digits % 3 == 0){
        itr = digits/3;
    }else{
        itr = digits/3 + 1;
    }

    ll int d = 100;
    while(itr){
        int count[1000] = {0};

        for(int i = 0;i<n;i++){
            int index = get_chunk(arr[i],d);
            count[index]++;
        }

        for(int i = 1;i<=1000;i++){
            count[i] += count[i-1];
        }

        ll result[n];

        for(int i = n - 1;i>=0;i--){
            int index = get_chunk(arr[i],d);
            result[--count[index]] = arr[i]; 
        }

        for(int i = 0;i<n;i++){
            cout << result[i] << " ";
        }

        cout << endl;
        d *= 1000;
        itr--;
    }
}
int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll m = 0;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        m = max(m,a[i]);
    }
    
    print_chunk(a,n);
    // print(a,n);
}