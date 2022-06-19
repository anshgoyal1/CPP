#include<iostream>
#include<algorithm>
using namespace std;
#include<unordered_map>
#include<vector>
#include<queue>
int main(){
    int n,i;
    cin >> n;
    unordered_map<int,int> map;
    vector<int> vec;
    for(i=0;i<n;i++){
        int a;
        cin >> a;
        map[a]++;
        if(std::count(vec.begin(),vec.end(),a) == 0){
            vec.push_back(a);
        }
    }
    priority_queue<int> q;
    auto itr = map.begin();
    while(itr != map.end()){
        q.push(itr->second);
        itr++;
    }
    while(!q.empty()){
        int count = q.top();
        q.pop();
        auto itr = vec.begin();
        while(itr!=vec.end()){
            if(map[*itr] == count){
                for(int j=0;j<count;j++){
                    cout<<*itr<<" ";
                }
                itr = vec.erase(itr);
                break;
            }
            else{
                itr++;
            }
        }
    }
    
}