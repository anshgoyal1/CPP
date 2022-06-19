#include<bits/stdc++.h> 
using namespace std;

bool compare(string s1,string s2){
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    while (s1[i] == s2[j]&& i > 0 && j > 0)
    {
        i--;
        j--;
    }
    return s1[i] > s2[j];
    
}
int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0;i<n;i++)
    cin >> a[i];

    sort(a.begin(),a.end(),compare);
    for(int i = n-1;i>=0;i--)
    cout << a[i] << " ";
}