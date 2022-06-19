#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<list<int>> adj(n + 1);
    int x,y;
    while(1){
        cin >> x;
        if(x == -1){
            break;
        }
        cin >> y;
        adj[x].push_back(y);
    }
    int i;
    for(i = 1;i<=n;i++){
        if(adj[i].empty()){
            break;
        }
    }
    bool isTrue = true;
    
    for(int j = 1;j<i;j++){
        if(find(adj[j].begin(),adj[j].end(),i) == adj[j].end()){
            isTrue = false;
            break;
        }
    }
    for(int j = i+1;j<=n;j++){
        if(isTrue == true && find(adj[j].begin(),adj[j].end(),i) == adj[j].end()){
            isTrue = false;
            break;
        }
    }

    if(isTrue){
        cout << i << endl;
    }else{
        cout << -1 << endl;
    }
}