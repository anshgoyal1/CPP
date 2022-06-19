#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data= val;
        left = right = NULL;
    }
};

Node* insert_in_level_order(Node *root,int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }else{
            temp->left = new Node(val);
            return root;
        }
        if(temp->right){
            q.push(temp->right);
        }else{
            temp->right = new Node(val);
            return root;
        }
    }
    return root;
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void delete_deep(Node *root,Node *d_node){
    queue<Node *> q;
    q.push(root);
    Node *temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp == d_node){
            temp = NULL;
            delete (d_node);
            return;
        }

        if(temp->right){
            if(temp->right == d_node){
                temp->right = NULL;
                delete(d_node);
                return;
            }else{
                q.push(temp->right);
            }
        }
        if(temp->left){
            if(temp->left == d_node){
                temp->left = NULL;
                delete(d_node);
                return;
            }else{
                q.push(temp->left);
            }
        }
    }
}

Node *deletion(Node *root,int key){
    if(root == NULL){
        return NULL;
    }

    if(!(root->left && root->right)){
        if(root->data == key){
            return NULL;
        }else{
            return root;
        }
    }

    queue<Node *> q;
    q.push(root);

    Node *temp;
    Node *key_node;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->data == key){
            key_node = temp;
        }

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

    if(key_node != NULL){
        int x = temp->data;
        delete_deep(root,temp);
        key_node->data = x;
        
    }
    return root;
}

int preIndex = 0;
void printPost(int in[],int pre[],int inSrt,int inEnd,map<int,int> hm){
    if(inSrt > inEnd){
        return;
    }

    int index = hm[pre[preIndex++]];

    printPost(in,pre,inSrt,index - 1,hm);
    printPost(in,pre,index + 1,inEnd,hm);

    cout << in[index] << " ";
}

void preintPostMain(int in[],int pre[],int n){
    map<int,int> mp;
    for(int i = 0;i<n;i++){
        mp[in[i]] = i;
    }

    printPost(in,pre,0,n-1,mp);
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right=  new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    inorder(root);

    cout << endl;
 
    int key = 12;
    root = insert_in_level_order(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;
}