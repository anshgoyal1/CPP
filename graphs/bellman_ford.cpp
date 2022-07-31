#include <bits/stdc++.h>
using namespace std;
#define int long long
#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

void solve()
{
    int N = 6, m = 7;
    vector<node> edges;
    edges.push_back(node(0, 1, 5));
    edges.push_back(node(1, 2, -2));
    edges.push_back(node(1, 5, -3));
    edges.push_back(node(2, 4, 3));
    edges.push_back(node(3, 2, 6));
    edges.push_back(node(3, 4, -2));
    edges.push_back(node(5, 3, 1));
    int src = 0;
    int inf = 10000000;

    vector<int> dist(n + 1, inf);
    dist[0] = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int fl = 0;

    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << "There is a cylce";
            fl = 1;
            break;
        }
    }

    if (!fl)
    {
        display(dist);
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)

        solve();

    return 0;
}