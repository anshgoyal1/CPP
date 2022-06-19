#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}
void DFS_Util(vector<int> adj[], int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    for (auto it : adj[v])
    {
        if (!visited[it])
        {
            DFS_Util(adj, it, visited);
        }
    }
}
void DFS(vector<int> adj[], int v)
{
    bool visited[4] = {false};

    DFS_Util(adj, v, visited);
}

bool isCycleUtil(int v, vector<int> adj[], bool visited[], bool recStack[])
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        for (auto it : adj[v])
        {
            if (!visited[it] && isCycleUtil(it, adj, visited, recStack))
            {
                return true;
            }
            else if (recStack[it])
            {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}
bool inCyclic(vector<int> adj[], int v)
{
    bool visited[v + 1] = {false};
    bool recStack[v + 1] = {false};

    for (int i = 0; i < v; i++)
    {
        if (isCycleUtil(i, adj, visited, recStack))
        {
            return true;
        }
    }
    return false;
}

bool isCycleUtil2(int v, vector<int> adj[], bool visited[], int parent)
{

    visited[v] = true;

    for (auto it : adj[v])
    {
        if (!visited[it] && isCycleUtil2(it, adj, visited, v))
        {
            return true;
        }
        if (it != parent)
        {
            return true;
        }
    }

    return false;
}
bool inCyclic2(vector<int> adj[], int v)
{
    bool visited[v + 1] = {false};

    for (int i = 0; i < v; i++)
    {
        if (isCycleUtil2(i, adj, visited, -1))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    DFS(adj, 2);
}