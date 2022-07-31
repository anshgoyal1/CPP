#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>>adj[1001];
    bool marked[1001];
    int prim(int x)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,x});
        int ans=0;
        while(!pq.empty())
        {
            pair<int,int>p=pq.top();
            pq.pop();
            x=p.second;
            if(marked[x]) continue;
            marked[x]=true;
            ans+=p.first;
            for(auto it:adj[x])
            {
                if(!marked[it.second]) pq.push(it);
            }
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        memset(marked,false,1001);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({dis,j});              
                adj[j].push_back({dis,i});
            }                
        }
        return prim(0);
    }
};

void prim(vector<pair<int, int>> adj[], int n)
{
  vector<int> keys(n, INT_MAX);
  vector<int> parent(n, -1);
  vector<bool> mstSet(n, false);

  keys[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < n - 1; count++)
  {
    int mini = INT_MAX;
    int u;

    for (int v = 0; v < n; v++)
    {
      if (mstSet[v] == false && keys[v] < mini)
      {
        mini = keys[v];
        u = v;
      }
    }

    mstSet[u] = true;
    for (auto it : adj[u])
    {
      int v = it.first;
      int weight = it.second;

      if (mstSet[v] == false && weight < keys[v])
      {
        keys[v] = weight;
        parent[v] = u;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << i << " " << parent[i] << endl;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> adj[n];
  int u, v, w;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int parent[n];
  int key[n];
  bool mstSet[n];

  for (int i = 0; i < n; i++)
  {
    mstSet[i] = false;
    keys[i] = INT_MAX;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  keys[0] = 0;
  parent[0] = -1;
  pq.push({0, 0});

  while (!pq.empty())
  {
    pair<int, int> p = pq.top();
    pq.pop();
    u = p.second;
    mstSet[u] = true;
    for (auto it : adj[u])
    {
      int v = it.second;
      int w = it.first;

      if (mstSet[v] == false && w < keys[v])
      {
        parent[v] = u;
        keys[u] = w;
        pq.push({keys[v], v});
      }
    }
  }
  for (int i = 1; i < n; i++)
  {
    cout << parent[i] << " - " << i << endl;
  }
}
