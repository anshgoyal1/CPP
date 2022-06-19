#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;

    int ans = -1;
    int x = -1;
    int y = -1;

    for(int i = 0;i<4;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        if(min(a,b) + min(c,d) <= n){
            ans = i + 1;
            x = min(a,b);
            y = n - x;
            break;
        }
    }

if(ans == -1){
    cout << -1 << endl;
    return;
}
    cout << ans << x << y << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;

    // while (t--)

    solve();

    return 0;
}