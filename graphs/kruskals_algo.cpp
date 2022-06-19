#include <bits/stdc++.h>
using namespace std;
struct node{
  int u,v,w;
  node(int first,int second,int weight){
    u = first;
    v = second;
    w = weight;
  }
};

bool comp(node a,node b){
  return a.w < b.w;
}

int find(int x,vector<int> &parent){
  if(parent[x] == x){
    return x;
  }

  return parent[x] = find(parent[x],parent);
}

void unionn(int u,int v,vector<int> &parent,vector<int> &rank){
  int x = find(u,parent);
  int y = find(v,parent);

  if(rank[u] < rank[v]){
    parent[u] = v;
  }else if(rank[u] > rank[v]){
    parent[v] = u;
  }else{
    parent[v] = u;
    rank[u]++;
  }
}

int main(){
  int n = 5;
  int m = 6;

  vector<node> edges;
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
  sort(edges.begin(),edges.end(),comp);

  vector<int> parent(n);
  for(int i = 0;i<n;i++){
    parent[i] = i;
  }
  vector<int> rank(n,0);

  int cost = 0;
  vector<pair<int,int>> mst;

  for(auto it:edges){
    if(find(it.u,parent) != find(it.v,parent)){
      cost += it.w;
      mst.push_back({it.u,it.v});
      unionn(it.u,it.v,parent,rank);
    }
  }
  cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl;
	return 0;
}
