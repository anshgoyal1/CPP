#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int m = 0;
        for(int i = 0;i<n;i++){
            cin >> a[i];
            m = max(m,a[i]);
        }

        vector<int> count_array(m+1,0);
        for(int i = 0;i<n;i++){
            count_array[a[i]]++;
            // cout << count_array[a[i]] << " ";
        }
        if(n == 1){
            cout << a[0] << " ";
            printf("%0.1f" , a[0]/1.0);
        }else{
            int ma = *max_element(count_array.begin(),count_array.end());
            for(int i = 0;i<=m+1;i++){
            if(count_array[i] == ma){
                cout << i << " ";
                break;
            }
        }
        for(int i = 1;i<=m;i++){
            count_array[i] = count_array[i] + count_array[i-1];
        }

        int output[n];
        for(int j = n - 1;j>=0;j--){
            output[count_array[a[j]]-1] = a[j];
            count_array[a[j]]--;
        }

        if(n % 2 != 0){
            printf("%0.1f",output[n/2]/1.0);
        }else{
            printf("%0.1f",(output[(n-1)/2] + output[n/2])/2.0);
        }
        cout << endl;
        }

        
    }
}