#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;    
};
struct Node *root = NULL;

void TreeCreate(){
    struct Node *p,*t;
    int x;
    queue<struct Node *> q;
    cout << "Enter root value : " << endl;
    cin >> x;
    root = new struct Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter the left child of : " << p->data;
        cin >> x;
        if(x != -1){
            t = new struct Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter the right child of : " << p->data;
        cin >> x;
        if(x != -1){
            t = new struct Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
    
}

void preorder(struct Node *p){
    if(p){
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
        
    }
}

void Ipreorder(struct Node *p){
    stack<struct Node *> s;
    while (p || !s.empty())
    {
        if(p){
            cout << p->data << " ";
            s.push(p);
            p = p->lchild;
        }else{
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

void Iinorder(struct Node *p){
    stack<struct Node *> s;
    while (p || !s.empty())
    {
        if(p){
            s.push(p);
            p = p->lchild;
        }
        else{
            p = s.top();
            s.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
    
}

void levelOrder(struct Node *p){
    queue<struct Node *> q;
    cout << p->data << " ";
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->lchild){
            cout << p->lchild->data << " ";
            q.push(p->lchild);
        }
        if(p->rchild){
            cout << p->rchild->data << " ";
            q.push(p->rchild);
        }
    }
    
}

int main(){
    TreeCreate();
    preorder(root);
    printf("\nPost Order ");
    Postorder(root);
}