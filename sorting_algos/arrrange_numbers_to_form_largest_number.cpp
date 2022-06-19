#include<bits/stdc++.h> 
using namespace std;

bool compare(string s1,string s2){
    string str1 = s1 + s2;
    string str2 = s2 + s1;

    return str2 > str1;
}
int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0;i<n;i++)
    cin >> a[i];

    sort(a.begin(),a.end(),compare);
    for(int i = n-1;i>=0;i--)
    cout << a[i];
}