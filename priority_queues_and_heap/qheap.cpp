#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    vector<int> a;
    int n;
    cin >> n;
    int q,v;
    for(int i = 0;i<n;i++){
        cin >> q;
        if(q == 1){
            cin >> v;
            a.push_back(v);
        }
        if(q == 2){
            cin >> v;
            int j;
            auto it = find(a.begin(),a.end(),v);
            a.erase(it);
        }
        if(q == 3){
            cout << *min_element(a.begin(),a.end()) << endl;
        }
    }
}
