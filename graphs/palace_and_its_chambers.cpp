#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<list<int>> adj(n + 1);
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

   for(int i = 1;i<=n;i++){
       if(find(adj[i].begin(),adj[i].end(),i + 1) 
       != adj[i].end()){
           c++;
       }
   }
    if(c == n - 1){
        cout << "Yes";
    }   else{
        cout << "No";
    }
}