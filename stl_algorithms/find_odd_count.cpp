#include<bits/stdc++.h>
using namespace std;

bool isodd(long long a){
    return (a % 2);
}

int reverseDigits(int num) 
{ 
    int rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num * 10 + num % 10; 
        num = num / 10; 
    } 
    return rev_num; 
} 
  
/* Function to check if n is Palindrome*/
bool isPalindrome(long long n) 
{ 
  
    // get the reverse of n 
    int rev_n = reverseDigits(n); 
  
    // Check if rev_n and n are same or not. 
    if (rev_n == n) 
        return true; 
    else
        return false; 
} 

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }

    auto it = unique(a.begin(),a.end());
    a.erase(it,a.end());
    replace_if(a.begin(),a.end(),isPalindrome,0);

    cout << count_if(a.begin(),a.end(),isodd);
}