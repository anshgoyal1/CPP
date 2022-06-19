#include<bits/stdc++.h>
using namespace std;

int euler_totient(int n){
    int result = n;

    for(int i = 2;i*i<=n;i++){

        if(n % i == 0){
            while(n % i == 0){
                n /= i;
            }
            result -= result / i;
        }
    }
    if(n > 1){
        result -= result / n;
    }
    return result;
}

vector<long long> phi_1_n(long long n){
    vector<long long> phi(n+1);
    phi[0] = 0;
    phi[1] = 1;
    for(long long i = 2;i<=n;i++){
        phi[i] = i - 1;
    }

    for(long long i = 2;i<=n;i++){
        for(long long j = 2*i;j<=n;j+=i){
            phi[j] -= phi[i];
        }
    }
    return phi;
}
int main(){
    long long n;
    cin >> n;
    vector<long long> p = phi_1_n(n);
    for(auto it: p){
        cout << it << " ";
    }
}