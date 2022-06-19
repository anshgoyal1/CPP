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

Node *remove_null_node(Node *node){
    if(node == NULL || node->data == INT_MAX){
        return NULL;
    }

    node->left = remove_null_node(node->left);
    node->right =remove_null_node(node->right);
    return node;
}

Node *insert_node(Node *node,int value,queue<Node *> &q){
    Node *new_node = create_node(value);
    if(node == NULL){
        node = new_node;
    }
    else if(q.front()->left == NULL){
        q.front()->left = new_node;
    }else{
        q.front()->right = new_node;
        q.pop();
    }

    if(value != INT_MAX){
        q.push(new_node);
    }
    return node;
}

void build_tree(){
    string temp;
    queue<Node *> q;
    while(cin >> temp){
        if(temp == "null"){
            root = insert_node(root,INT_MAX,q);
        }else{
            root = insert_node(root,stoi(temp),q);
        }
    }

    root = remove_null_node(root);
}
int get_max_depth(struct Node *node)
{
    if(node == NULL){
        return 0;
    }

    return max(1 + get_max_depth(node->left),
    1+get_max_depth(node->right));
}

int main()
{
    build_tree();
    int depth = get_max_depth(root);
    cout << depth;
    return 0;
}
