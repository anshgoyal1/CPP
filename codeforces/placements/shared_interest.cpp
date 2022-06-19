#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> from, vector<int> to, vector<int> weight, int n)
{

    map<int, set<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[weight[i]].insert(from[i]);
        m[weight[i]].insert(to[i]);
    }

    map<pair<int, int>, int> mp;
    int ma = INT_MIN;
    for (auto it : m)
    {
        set<int> s = it.second;
        vector<int> v(s.begin(), s.end());
        int siz = v.size();

        for (int i = 0; i < siz - 1; i++)
        {
            mp[{v[i], v[i + 1]}]++;

            if (ma < mp[{v[i], v[i + 1]}])
            {
                ma = mp[{v[i], v[i + 1]}];
            }
        }

        if (siz > 2)
        {
            mp[{v[0], v[siz - 1]}]++;
            if (ma < mp[{v[0], v[siz - 1]}])
            {
                ma = mp[{v[0], v[siz - 1]}];
            }
        }
    }

    int max_prod = INT_MIN;

    for (auto it : mp)
    {
        if (it.second == ma)
        {
            pair<int, int> p = it.first;
            max_prod = max(max_prod, p.first * p.second);
        }
    }

    cout << max_prod << endl;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> from;
    vector<int> to;
    vector<int> weight;

    for (int i = 0; i < edges; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        from.push_back(x);
        to.push_back(y);
        weight.push_back(z);
    }
    solve(from, to, weight, edges);
}
