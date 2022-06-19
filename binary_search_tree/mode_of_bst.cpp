#include <iostream>
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


Node *insert_node(Node *root,int value){
    
    Node *new_node = create_node(value);

    if(root == NULL){
        root = new_node;
    }else if(root->data > new_node->data){
        root->left = insert_node(root->left,value);
    }else if(root->data  < value){
        root->right = insert_node(root->right,value);
    }

    return root;
}

void create_tree(){
    string x;
    vector<int> v;
    while(cin >> x){
        if(x != "null")
        root = insert_node(root,stoi(x));
    }
    for(int i = 0;i<v.size();i++){
        root = insert_node(root,v[i]);
    }
}

int curr_value = -100000;
int curr_count = 0;
int max_count = 0;
int max_value;
void inorder_traversal(Node *root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    if(curr_value != root->data){
        curr_count = 0;
        curr_value = root->data;
    }else{
        curr_count++;
        if(curr_count > max_count){
            max_count = curr_count;
            max_value = curr_value;
        }
    }
    inorder_traversal(root->right);
}
int main()
{
    create_tree();
    inorder_traversal(root);
    cout << max_value << endl;
    return 0;
}
