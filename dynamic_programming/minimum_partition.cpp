#include <bits/stdc++.h>
using namespace std;

int findMinRecur(vector<int> a,int i,int sumTotal,int sumCalculated){
    if(i == 0){
        return abs(sumTotal - 2*sumCalculated);
    }

    return min(findMinRecur( a,i-1,sumTotal,sumCalculated + a[i - 1]),
    findMinRecur(a,i-1,sumTotal,sumCalculated));
}

int findMin(vector<int> a){
    int sum = 0;
    int n = a.size();
    for(int i = 0;i<n;i++){
        sum += a[i];
    }

    return findMinRecur(a,n,sum,0);
}

int main(){
    vector<int> a = {3,1,4,2,2,1};
    cout << findMin(a);
}