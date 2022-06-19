#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
int main(){
    vector<ll> a,b,s,z,s2;
    ll sum=0,k,s1=0,m,n,i,x;
    cin>>m>>n;
    for(i=0;i<m;i++){
        cin>>x;
        a.push_back(x);
    }
    for(i=0;i<n;i++){
        cin>>x;
        s1=s1+x;
        
        if(i<m){
            if(x==*(a.begin()+i)){
                z.push_back(i);
                s.push_back(s1);
                s1=0;
            }
        }
        if(i==n-1){
            
            s.push_back(s1);
            s1=0;
        }
        b.push_back(x);
    }
    if(z.empty()){
        z.push_back(-1);
    }
    s1=0;
    k=0;
    for(i=0;i<m;i++){
        s1=s1+*(a.begin()+i);
        if(i==*(z.begin()+k)){
            s2.push_back(s1);
            s1=0;
            k++;
        }
        if(i==m-1){
            s2.push_back(s1);
        }
        
    }
    
    
    sum=0;
    for(i=0;i<k+1;i++){
        
        if(*(s.begin()+i)>*(s2.begin()+i)){
            sum=sum+*(s.begin()+i);
        }
        else{
            sum=sum+*(s2.begin()+i);
        }
        
    }
    
    
    
    cout<<sum;
    return 0;
}