#include <bits/stdc++.h>
using namespace std;

class kqueues{
    int *arr;

    int *front;
    int *rear;
    int *next;
    int n,k;

    int free;

    public:
    kqueues(int n,int k);

    bool isFull(){ return free == -1;}

    void enqueue(int qn,int val);
    int dequeue(int qn);

    bool isEmpty(int qn){
        return front[qn] == -1;
    }
};

kqueues::kqueues(int n1,int k1){
    int n = n1,k = k1;
    arr = new int[n];
    front = new int[k];
    rear = new int[k];
    next = new int[n];

    for(int i = 0;i<k;i++){
        front[i] = -1;
    }

    free = 0;
    for(int i = 0;i<n-1;i++){
        next[i] = i+1;
     }
     next[n-1] = -1;
}

void kqueues::enqueue(int qn,int val){
    if(isFull()){
        return;
    }

    int i = free;
    free = next[i];

    if(isEmpty(qn)){
        front[qn] = i;
    }else{
        next[rear[qn]] = i;
    }

    next[i] = -1;
    rear[qn] = i;

    arr[i] = val;
}

int kqueues::dequeue(int qn){
    if(isEmpty(qn)){
        return INT_MAX;
    }

    int i = front[qn];
    front[qn] = next[i];
    next[i] = free;
    free = i;

    return arr[i];
}
int main(){

}