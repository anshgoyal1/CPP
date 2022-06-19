#include <bits/stdc++.h>
using namespace std;

vector<long long> trial_division(long long n){
    vector<long long> factorization;
    while(n % 2 == 0){
        factorization.push_back(2);
        n /= 2;
    }

    for(long long i = 3;i<= sqrt(n);i+=2){
        while(n % i == 0){
            factorization.push_back(i);
            n /= i;
        }
    }
    if(n > 1){
        factorization.push_back(n);
    }
    return factorization;
}

int main(){

}