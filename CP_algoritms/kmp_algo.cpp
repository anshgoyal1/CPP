#include <bits/stdc++.h>
using namespace std;

void computeLPS(string pat,vector<int> &lps){
    int n = pat.length();

    int len = 0;
    lps[0] = 0;

    int i = 1;
    while(i < n){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lps[len - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(string pat,string txt){
    int m = pat.length();
    int n = txt.length();
    
    vector<int> lps(m);
    computeLPS(pat,lps);

    int i = 0;
    int j = 0;
    while(i < n){
        if(pat[j] == txt[i]){
            i++;j++;
        }
        if(j == m){
            cout << "Found at: " << j - i << endl;
            j = lps[j - 1];
        }

        else if(i < n && pat[j] != txt[i]){
            if(j != 0){
                j = lps[j - 1];
            }else{
                i = i+1;
            }
        }
    }
}

int main(){
    string pat = "ABABCABAB";
    string txt = "ABABDABACDABABCABAB";
    kmpSearch(pat,txt);
    return 0;
}