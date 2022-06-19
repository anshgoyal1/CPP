#include<bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int> adj[], int* vis, int* inDeg,
         int* outDeg)
{
    // Mark the source as visited
    vis[u] = 1;
 
    // Mark in-degree as 1
    inDeg[u] = 1;
 
    // Traversing adjacent nodes
    for (auto v : adj[u]) 
    {
        // If not visited
        if (vis[v] == 0) 
        {
            // Mark out-degree as 1
            outDeg[u] = 1;
 
            // DFS Traversal on
            // adjacent vertex
            dfs(v, adj, vis, inDeg, outDeg);
        }
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    int Indegree[n+1] = {0};
    int Outdegree[n+1] = {0};
    int visited[n+1] = {0};

    vector<int> adj[n + 1];

    int source,dest;
    for(int i = 0;i<k;i++){
        cin >> source >> dest;
        adj[source].push_back(dest);
    }
    dfs(1,adj,visited,Indegree,Outdegree);

    int minEdges = 0;

    int totalIndegree = 0;
    int totalOutdegree = 0;

    for(int i = 1;i<=n;i++){

        if(Indegree[i] == 1){
            totalIndegree++;
        }
        if(Outdegree[i] == 1){
            totalOutdegree++;
        }
    }

    minEdges = max(n -totalIndegree,n - totalOutdegree);

    cout << minEdges  << endl;
}