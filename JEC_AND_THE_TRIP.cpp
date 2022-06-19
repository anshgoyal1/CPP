#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin >> s;
    int cnt[26] = {0};

    for(auto it:s){
        cnt[it - 'a']++;
    }

    for(int i = 0;i<26;i++){
        if(cnt[i] == 0){
            char ans = 'a' + i;
            cout << ans << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)

        solve();

    return 0;
}