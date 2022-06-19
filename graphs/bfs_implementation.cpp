#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int v,int u){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void BFS(vector<int> adj[],int N){
    bool visited[N + 1] = {false};

    int s = 1;
    visited[s] = true;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for(auto it: adj[curr]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
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
        cin >> vertex >> edges;
        addEdge(adj,edges,vertex);
    }
    BFS(adj,n);
}