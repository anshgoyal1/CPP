#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll partition(ll a[],ll l,ll r,ll x){
    ll i;
    for(i = l;i<r;i++){
        if(a[i] == x){
            break;
        }
    }
    swap(a[i],a[r]);

    i = l;
    for(ll j = l;j<r;j++){
        if(a[j] <= x){
            swap(a[j],a[i]);
            i++;
        }
    }
    swap(a[i],a[r]);
    return i;
}

ll findMedian(ll a[],ll n){
    sort(a,a+n);
    return a[n/2];
}

ll kthSmallest(ll a[],ll l,ll r,ll k){
    if(k > 0 && k <= r - l + 1){
        ll n = r - l + 1;

        ll i,median[(n+4)/5];
        for(i = 0; i < n / 5;i++){
            median[i] = findMedian(a + l + i*5,5);
        }
        if(i * 5 < n){
            median[i] = findMedian(a + l *i*5 ,n%5);
            i++;
        }

        ll medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        ll pos = partition(a,l,r,medOfMed);

        if(pos - l == k - 1)
        {
            return a[pos];
        }else if(pos - l > k - 1){
            return kthSmallest(a,l,pos - 1,k);
        }
        
        return kthSmallest(a,pos + 1,r,k - pos + l - 1);
    }
    return INT_MAX;
}
int main(){
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }

    ll k;
    cin >> k;
    cout << kthSmallest(a,0,n - 1,k);

}