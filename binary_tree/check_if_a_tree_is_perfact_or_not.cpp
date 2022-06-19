#include <iostream>
#include<bits/stdc++.h>

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

Node* create_tree(vector<int> a,int i){
    if(i >= a.size()){
        return NULL;
    }

    struct Node *node = create_node(a[i]);
    node->left = create_tree(a,2*i+1);
    node->right = create_tree(a,2*i+2);
    return node;
}

void insert_node(){
    vector<int> a;
    int temp;
    while(cin >> temp){
        a.push_back(temp);
    }

    root = create_tree(a,0);
}

int depth(struct Node *node){
    int d = 0;
    while(node != NULL){
        d++;
        node = node->left;
    }
    return d;
}
bool check_perfect_binary_tree(struct Node *node,int d,int level = 0)
{
    if(node == NULL){
        return true;
    }

    if(node->left == NULL && node->right == NULL){
        return (d == level+1);
    }

    if(node->right == NULL || node->left == NULL){
        return false;
    }

    return check_perfect_binary_tree(node->left,d,level+1) &&
        check_perfect_binary_tree(node->right,d,level+1);
}

bool isPerfact(struct Node *node){
    int d = depth(node);
    return check_perfect_binary_tree(node,d);
}

int main()
{
    insert_node();
    cout << isPerfact(root) << endl;
    return 0;
}
