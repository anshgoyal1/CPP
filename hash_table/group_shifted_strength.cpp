#include<bits/stdc++.h>
using namespace std;

bool check(string s1,string s2){
    int k = s1[0] - s2[0];
    for(int i = 1;i<s1.length();i++){
        if(k != s1[i] - s2[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;

    set<int> lengths;
    multimap<int,string> map;
    for(int i= 0;i<n;i++){
        string s;
        cin >> s;
        lengths.insert(s.length());
        map.insert(make_pair(s.length(),s));
    }

    vector<int> v;

    for(auto i:lengths){
        if(i == 1){
            v.push_back(1);
        }else{
            set<string> et;
            auto it = map.equal_range(i);
            for(auto itr = it.first;itr != it.second;itr++){
                string s=itr->second;

                int o=s[0]-'a';

           for(int m=0;m<s.length();m++)

             { 
                 int f=s[m]-'a'-o;

               s[m]=char('a'+(26+f)%26);

             }

            et.insert(s);
            }
            v.push_back(et.size());
        }
    }
    for(auto i:v){
        cout << i << " ";
    }

}