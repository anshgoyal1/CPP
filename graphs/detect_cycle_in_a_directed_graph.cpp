#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<int> a[],int v,bool *visited,bool *rec){
    if(!visited[v]){
        visited[v] = true;
        rec[v]= true;

        for(auto it:a[v]){
            if(!visited[it] && isCyclicUtil(a,it,visited,rec)){
                return true;
            }
            else if(rec[it]){
                return true;
            }
        }

    }
    rec[v] = false;
    return false;
}

bool isCyclic(vector<int> adj[],int N){
    bool visited[N + 1] = {false};
    bool rec[N + 1] = {false};

    for(int i = 0;i<N;i++){
        if(isCyclicUtil(adj,i,visited,rec)){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> adj[n+1];
    int x,y;
    int c = 0;
   for(int i = 0;i<n;i++){
       cin >> x;

       while(1){
           cin >> y;
           if(y == -1){
               break;
           }

           adj[x].push_back(y);
       }
   }
    if(isCyclic(adj,n)){
        cout << "Yes";
    }else{
        cout << "No";
    }
   
}