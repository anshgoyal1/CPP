#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
} * root;

Node *create_node(int data)
{
    Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

Node *remove_null_nodes(Node *root)
{
    if (root == NULL || root->data == INT_MAX)
        return NULL;

    root->left = remove_null_nodes(root->left);
    root->right = remove_null_nodes(root->right);

    return root;
}

Node *insert_node(Node *root, int value, queue<Node *> &queue)
{
    Node *new_node = create_node(value);
    if (root == NULL)
        root = new_node;
    else if (queue.front()->left == NULL)
        queue.front()->left = new_node;
    else
    {
        queue.front()->right = new_node;
        queue.pop();
    }

    if (value != INT_MAX)
        queue.push(new_node);
    return root;
}

void build_tree()
{
    string temp;
    queue<Node *> queue;
    while (cin >> temp)
    {
        if (temp == "null")
            root = insert_node(root, INT_MAX, queue);
        else
            root = insert_node(root, stoi(temp), queue);
    }
    root = remove_null_nodes(root);
}

void right_Side_view(Node *root){
    if(root!= NULL){
        cout << root->data << " ";
    }

    if(root->right!= NULL){
        return right_Side_view(root->right);
    }else if(root->left != NULL){
        return right_Side_view(root->left);
    }
}
int main()
{
    build_tree();
    right_Side_view(root);
    return 0;
}
