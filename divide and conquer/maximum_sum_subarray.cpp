#include<bits/stdc++.h>
#define ll long long
using namespace std;


int kadane_algo(vector<int> a,int n){
    int max_so_far = 0;
    int max_ending_here = 0;
    for(int i = 0;i<n;i++){
        max_ending_here += a[i];

        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here;
        }
        if(max_ending_here < 0){
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

ll find_cross_sum(vector<int> a,int low,int mid,int high){
    ll left_sum = LLONG_MIN;
    ll sum = 0;
    for(int i = mid;i>=low;i--){
        sum += a[i];
        left_sum = max(left_sum,sum);
    }

    ll right_sum = LLONG_MIN;
    ll sum2 = 0;
    for(int i = mid + 1;i<=high;i++){
        sum2 += a[i];
        right_sum = max(right_sum,sum2);
    }

    return (left_sum + right_sum);
}

ll max_sum(vector<int> a,int low,int high){
    if(high == low){
        return a[low];
    }
    else{
        int mid = (high + low) / 2;
        ll left_sum = max_sum(a,low,mid);
        ll right_sum = max_sum(a,mid+1,high);
        ll cross_sum = find_cross_sum(a,low,mid,high);

        return max(cross_sum,max(left_sum,right_sum));
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    ll sum = max_sum(a,0,n);
    cout << sum << endl;

    return 0;
}
