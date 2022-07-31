#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<bool> &vis, int u, stack<int> &st)
{
    vis[u] = true;
    for (auto it : adj[u])
    {
        if (!vis[it])
        {
            dfs(adj, vis, it, st);
        }
    }

    st.push(u);
}

void rev_dfs(vector<int> transpose[], int u, vector<bool> &vis)
{
    cout << u << " ";
    vis[u] = true;

    for (auto it : transpose[u])
    {
        if (!vis[it])
        {
            rev_dfs(transpose, it, vis);
        }
    }
}

int main()
{
    int n = 6, m = 7;
    vector<int> adj[n + 1];
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(4);
    adj[6].push_back(5);

    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(adj, visited, i, st);
        }
    }

    vector<int> transpose[n + 1];
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    while (!st.empty())
    {
        int x = st.top();
        st.pop();

        if (!visited[x])
        {
            rev_dfs(transpose, x, visited);
            cout << endl;
        }
    }
}