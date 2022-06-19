#include<bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Node *root = NULL;

void createTree(){
    struct Node *p,*t;
    int x;
    queue<struct Node *> q;
    cout << "Enter the root: ";
    cin >> x;
    root = new struct Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter the left child : ";
        cin >> x;
        if(x != -1){
            t = new struct Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            root->lchild = t;
            q.push(t);
        }

        cout << "Enter the right child : ";
        cin >> x;
        if(x != -1){
            t = new struct Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            root->rchild = t;
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

void inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

void postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
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
        }else{
            p = s.top();
            s.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
    
}

void levelorder(struct Node *p){
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

int count(struct Node *p){
    if(p){
        return count(p->lchild) + count(p->rchild) + 1;
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

int main(){
    createTree();
    cout << count(root) << endl;
    cout << height(root) << endl;
    return 0;
}