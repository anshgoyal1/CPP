#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first = NULL;

void create(int a[],int n){
    int i;
    struct Node *t,*last;
    first = new struct Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for(i = 1;i<n;i++){
        t = new struct Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(){
    struct Node *k = first;
    while(k != NULL){
        cout << k->data << " ";
        k = k->next;
    }
}

void reverse(struct Node *p){
    struct Node *q = NULL;
    struct Node *r = NULL;

    while(p != NULL){
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
}

int main(){

}