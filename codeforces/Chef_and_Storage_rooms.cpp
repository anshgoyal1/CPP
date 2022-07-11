#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, q;
    cin >> n >> q;
    int totalRooms = (n * 4) - 4;
    int room = 1;

    for (int i = 0; i < q; i++)
    {
        int e, x;
        cin >> e;

        if (e == 0)
        {
            cin >> x;
            x %= totalRooms;
            room += x;
            room = (room % totalRooms);
            if (room == 0)
            {
                room = totalRooms;
            }
        }
        else if (e == 1)
        {
            cin >> x;
            x %= totalRooms;
            room -= x;
            if (room <= 0)
            {
                room = totalRooms + (room % totalRooms);
            }
        }
        else if (e == 2)
        {
            room = 1;
        }

        // cout << "Room " << room << endl;
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    cout << room << endl;
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