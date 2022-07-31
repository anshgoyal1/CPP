#include <bits/stdc++.h>
using namespace std;

int squared_dist(pair<int, int> a, pair<int, int> b)
{
    int x = (pow(a.first - b.first, 2) +
             pow(a.second - b.second, 2));
    return x;
}

int mex(vector<int> &a, int x)
{
    int n = a.size();
    vector<int> rem(x, 0);
    for (auto it : a)
    {
        rem[it % x]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (--rem[i % x] < 0)
        {
            return i;
        }
    }

    return n;
}

void solve(string a,string b){
    int n = a.length();
    int m = b.length();
    int cnt1[26] = {0};
    int cnt2[26] = {0};

    for(auto it:a){
        cnt1[it - 'a']++;
    }
    for(auto it:b){
        cnt2[it - 'a']++;
    }

    string half,mid;
    for(int i = 0;i<26;i++){
        char c = 'a' + i;
        int c1 = cnt1[i] / 2;
        int c2 = cnt2[i] / 2;
        half += string(c1 + c2,c);

        if(cnt1[i] % 2 == 1 and cnt2[i] % 2 == 1 && mid.length() < 2){
            mid = string(2,c);
        }

        if((cnt1[i] % 2 == 1 or cnt2[i] % 2 == 1) && mid.length() == 0){
            mid = string(1,c);
        }
    }

    if(mid.length() == 2){
        half.push_back(mid[0]);

        mid = "";
    }

    sort(half.begin(),half.end());
    string rev = half;
    reverse(rev.begin(),rev.end());
    cout << half + mid + rev << endl;
}
int main()
{
    int n = 3;
    vector<int> a = {0, 1, 2, 1, 3};
    cout << mex(a, n) << endl;
}
