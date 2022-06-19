#include <bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root = NULL;

int NodeHeight(struct Node *p){
    int hl,hr;
    hl = p && p->lchild? p->lchild->height:0;
    hr = p && p->rchild? p->rchild->height:0;
    return max(hl,hr)+1;
}

int BalanceFactor(struct Node *p){
    int hl,hr;
    hl = p && p->lchild? p->lchild->height:0;
    hr = p && p->rchild? p->rchild->height:0;
    return hl - hr;
}

struct Node *LLrotation(struct Node *p){
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    pl->lchild = plr;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);

    if(root == p){
        root = pl;
    }
    return pl;
}
struct Node *LRrotation(struct Node *p){
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->rchild;
    pl->lchild = plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
    if(root == p){
        root = pl;
    }
    return plr;
}

struct Node *Rinsert(struct Node *p,int key){
    struct Node *t = NULL;

    if(p == NULL){
        t = new struct Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        t->height = 1;
        return t;
    }

    if(p->data > key){
        return Rinsert(p->lchild,key);
    }else if(p->data < key){
        return Rinsert(p->rchild,key);
    }

    p->height = NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
    return LLrotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
    return LRrotation(p);
    
    return p;
}

int main(){

}