#include<bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void insert(int key){
    struct Node *t = root;
    struct Node *p,*r;

    if(root == NULL){
        p = new struct Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t)
    {
        r = t;
        if(key < t->data){
            t = t->lchild;
        }else if(key > t->data){
            t = t->rchild;
        }else{
            return;
        }
    }
    p = new struct Node;
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(key < r->data){
        r->lchild = p;
    }else{
        r->rchild = p;
    }
}

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

int height(struct Node *root){
    int x = 0;
    int y = 0;
    if(!root){
        return 0;
    }

    x = height(root->lchild);
    y = height(root->rchild);
    if(x > y){
        return x + 1;
    }else{
        return y + 1;
    }
}

struct Node * Search(int key)
{
    struct Node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        return t;
        else if(key<t->data)
        t=t->lchild;
        else
        t=t->rchild;
    }
    return NULL;
}

struct Node *Rinsert(struct Node *p,int key){
    struct Node *t = NULL;
    if(p == NULL){
        t = new struct Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(p->data > key){
        return Rinsert(p->lchild,key);
    }else if(p->data < key) {
        return Rinsert(p->rchild,key);
    }
}

struct Node *Inpre(struct Node *p){
    while (p && p->rchild != NULL){
        p = p->rchild;
    }
    return p;    
}

struct Node *InSucc(struct Node *p){
    while (p && p->lchild != NULL){
        p = p->lchild;
    }
    return p;    
}

struct Node *Rdelete(struct Node *p,int key){
    struct Node *q;
    if(p == NULL){
        return NULL;
    }

    if(p->lchild == NULL && p->rchild == NULL){
        if(p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if(p->data > key){
        p->lchild = Rdelete(p->lchild,key);
    }else if(p->data < key){
        p->rchild = Rdelete(p->rchild,key);
    }else{
        if(height(p->lchild) > height(p->rchild)){
            q = Inpre(p->lchild);
            p->data = q->data;
            Rdelete(p->lchild,q->data);
        }else{
            q = InSucc(p->rchild);
            p->data = q->data;
            Rdelete(p->lchild,q->data);
        }
    }
    return p;
}
int main(){
    insert(10);
    insert(5);
    insert(20);
    insert(30);
    insert(25);

    Inorder(root);
}