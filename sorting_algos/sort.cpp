#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &a,int n){
    int key;

    for(int i = 1;i<n;i++){
        key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = key;
    }

}

void bubble_sort(vector<int> &a,int n){
    for(int i = 0;i<n - 1;i++){
        for(int j = 0;j<n - i - 1;j++){
            if(a[j+1] < a[j]){
                swap(a[j+1],a[j]);
            }
        }
    }
}

void selection_sort(vector<int> &a,int n){
    int min_index;

    for(int i = 0;i<n- 1;i++){
        min_index = i;
        for(int j = i + 1;j<n;j++){
            if(a[j] < a[min_index]){
                min_index = j;
            }
        }
        swap(a[min_index],a[i]);
    }
}

int partition(vector<int> &a,int low,int high){
    int pivot = a[high];
    int j = low - 1;

    for(int i = low;i<high;i++){
        if(a[i] <= pivot){
            j++;
            swap(a[i],a[j]);
        }
    }
    swap(a[j+1],a[high]);
    return j+1;
}

void quick_sort(vector<int> &a,int low,int high){
    if(high > low){
        int part = partition(a,low,high);

        quick_sort(a,low,part-1);
        quick_sort(a,part + 1,high);
    }
}

void merge(vector<int> &a,int l,int m,int r){
    int i,j,k;

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1],R[n2];

    for(int i = 0;i<n1;i++){
        L[i] = a[l + i];
    }

    for(int j = 0;j<n2;j++){
        R[j] = a[m + j + 1];
    }

    i = j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k++] = L[i++];
        }else{
            a[k++] = R[j++];
        }
    }

    while(i < n1){
        a[k++] = L[i++];
    }

    while(j < n2){
        a[k++] = R[j++];
    }
}

void mergesort(vector<int> &a,int l,int r){
    if(l < r){
        int m = l+(r-l)/2;

        mergesort(a,l,m);
        mergesort(a,m + 1,r);

        merge(a,l,m,r);
    }
}

void countSort(vector<int> &a,int n){
    map<int,int> m;
    for(auto it:a){
        m[it]++;
    }

    a.clear();

    for(auto it:m){
        while(it.second > 0){
            a.push_back(it.first);
            it.second--;
        }
    }
}
int main(){
    vector<int> arr = {5,2,3,9,4,22,1,-1};

    int n = arr.size();
    countSort(arr,n);
    for(auto it:arr){
        cout << it << " ";
    }
     cout << endl;
}