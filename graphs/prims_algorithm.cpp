#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  vector<pair<int,int>> adj[n];
  int u,v,w;
  for(int i = 0;i<m;i++){
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  int parent[n];
  int key[n];
  bool mstSet[n];

  for(int i = 0;i<n;i++){
    mstSet[i] = false;
    keys[i] = INT_MAX;
  }

  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  keys[0] = 0;
  parent[0] = -1;
  pq.push({0,0});

  while(!pq.empty()){
    pair<int,int> p = pq.top();
    pq.pop();
    u = p.second;
    mstSet[u] = true;
    for(auto it:adj[u]){
      int v = it.first;
      int w = it.second;

      if(mstSet[v] == false&& w < keys[v]){
        parent[v] = u;
        keys[u] = w;
        pq.push({keys[v],v});
      }
    }
  }
  for(int i = 1;i<n;i++){
    cout << parent[i] << " - " << i << endl;
  }
}
