#include<bits/stdc++.h> 
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    
    vector<long long> b(n);
    for(int i = 0;i<n;i++){
    cin >> a[i];
    
    }
    for(int i = 0;i<n;i++){

    cin >> b[i];
    }
    vector<long long> c(a);
    sort(c.begin(),c.end());

    int l = 0;
    long long sum1 = 0;
    
    long long sum2 = 0;
    int j = n-1;
    while(sum2 <= sum1 && j >= 0){
        sum1 += c[j];
        int index = find(a.begin(),a.end(),c[j]) - a.begin();
        sum2 += b[index];
        cout << sum1 << " " << index << " " << sum2 << endl; 
        if(sum2 > sum1){
            break;
        }else{
            l++;
        }
        j--;
    }
    cout<< l << endl;
}