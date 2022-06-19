#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
}*root;

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}


Node *insert_node(Node *node,Node *new_node){
    
    if(node == NULL){
        node = new_node;
    }
    else if(node->data > new_node->data){
        node->left = insert_node(node->left,new_node);
    }else if(node->data <= new_node->data){
        node->right = insert_node(node->right,new_node);
    }

    return node;
}

void create_tree(){
    int k;
    vector<int> a;

    while(k != -1){
        cin >> k;
        if(k == -1){
            break;
        }
        a.push_back(k);
    }

    for(int i =0;i<a.size(); i++){
        Node *new_node = create_node(a[i]);
        root = insert_node(root,new_node);
    }
}

int get_min(struct Node *root) {
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}


int get_max(struct Node *root) {
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

void preorder_traverse(Node *root) {
    if(root == NULL){
        return; 
    }

    cout << root->data << " ";
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

int count(Node *root){
    if(root == NULL) {
        return 0;
    }

    return 1 + count(root->left) + count(root->right);
}

int inorder(Node *root,int k,int &c){
    if(root){
        inorder(root->left,k,c);
        c++;
        if(k == c){
            return root->data;
        }
        inorder(root->right,k,c);
    }
    return -1;
}

int median(Node *root){
    int k = count(root);
    int c = 0;
    if(k % 2 == 1){
        return inorder(root,(k + 1)/2,c);
    }else{
        return inorder(root,(k/2 + (k + 1)/2)/2,c);
    }
}

void insert(Node *&root,int data,Node *&succ){
    if(root == NULL){
        root = new Node(data);
    }

    if(data < root->data){
        succ = root;
        insert(root->left,data,succ);
    }

    else if(data > root->data){
        insert(root->right,data,succ);
    }
}

void replace(int a[],int n){
    Node *root = NULL;
    for(int i = n - 1;i>=0;i--){
        Node* succ = NULL;
        insert(root,a[i],succ);

        if(succ){
            a[i] = succ->data;
        }else{
            a[i] = -1;
        }
    }
}
int main()
{
    create_tree();
    cout << median(root) << endl;

    preorder_traverse(root);
    return 0;
}
