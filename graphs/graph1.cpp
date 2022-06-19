#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclicUtil(vector<int> adj[], int v, bool visited[], bool *recStack)
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        for (auto it : adj[v])
        {
            if (!visited[it] && isCyclicUtil(adj, it, visited, recStack))
                return true;
            if (recStack[it])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(vector<int> adj[])
{
    bool visited[6] = {false};
    bool recStack[6] = {false};

    for (int i = 0; i < 6; i++)
    {
        if (isCyclicUtil(adj, i, visited, recStack))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> adj[6];
}