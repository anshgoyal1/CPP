#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int v,int u){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void DFS_Util(vector<int> adj[],int v,bool *visited){
    visited[v] = true;
    cout << v << " ";

    for(auto i: adj[v]){
        if(!visited[i]){
            DFS_Util(adj,i,visited);
        }
    }
}

void DFS(vector<int> adj[],int N){
    bool visited[N + 1] = {false};

    DFS_Util(adj,1,visited);
}




void topological_sort_util(vector<int> adj[],int v,bool visited[],stack<int> &s){
    visited[v] = true;

    for(auto it: adj[v]){
        if(!visited[it]){
            topological_sort_util(adj,it,visited,s);
        }
    }
    s.push(v);
}

void topological_sort(vector<int> adj[],int V){
    stack<int> S;
    bool visited[V + 1] = {false};

    for(int i = 0;i<V;i++){
        if(!visited[i]){
            topological_sort_util(adj,i,visited,S);
        }
    }
    while(!S.empty()){
        cout << S.top() << " ";
        S.pop();
    }
}

void dfs(vector<int> adj[],int V){
    bool visited[V + 1] = {false};

    queue<int> q;
    int s = 1;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        cout << x << " ";

        for(int i = 0;i<adj[x].size();i++){
            if(!visited[adj[x][i]]){
                visited[adj[x][i]] = true;

                q.push(adj[x][i]);
            }
        }
    }
}

void dijkstra(vector<pair<int,int>> adj[],int v,int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(v,INT_MAX);

    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.front();
        pq.pop();

        for(auto it:adj[u]){
            int v = it.first;
            int weight = it.second;

            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;

                pq.push(make_pair(dist[v],v));
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> adj[n+1];
    int vertex,edges;
    for(int i = 0;i<n;i++){
        cin >> vertex;
        while (1)
        {
            cin >> edges;
            if(edges == -1){
                break;
            }
            addEdge(adj,vertex,edges);
        }
    }
    DFS(adj,n);
    cout << endl;
    topological_sort(adj,n);
}