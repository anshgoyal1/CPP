#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll numSquareSum(ll n) 
{ 
    ll squareSum = 0; 
    while (n) 
    { 
        squareSum += (n % 10) * (n % 10); 
        n /= 10; 
    } 
    return squareSum; 
} 
bool happy_number(){
    ll n;
    cin >> n;
    set<ll> s;
    while(1){
        n = numSquareSum(n);
        if(n == 1){
            return true;
        }else if(s.find(n) != s.end()){
            return false;
        }
        s.insert(n);
    }
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        bool result = happy_number();
        if(result){
            cout << "Happy Number" << endl;
        }else{
            cout << "Not a Happy Number" << endl;
        }
    }
}