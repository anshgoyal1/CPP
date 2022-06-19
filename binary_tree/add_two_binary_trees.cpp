#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
}*root1 = NULL,*root2 = NULL;

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

Node *remove_null_nodes(Node *node){
    if(node == NULL || node->data == INT_MAX){
        return NULL;
    }

    node->left = remove_null_nodes(node->left);
    node->right = remove_null_nodes(node->right);

    return node;
}

Node *insert_node(Node *node,int value,queue<Node *> &q){
    Node *new_node = create_node(value);

    if(node == NULL){
        node= new_node;
    }
    else if(q.front()->left == NULL){
        q.front()->left = new_node;
    }
    else{
        q.front()->right = new_node;
        q.pop();
    }

    if(value != INT_MAX){
        q.push(new_node);
    }
    return node;
}

void build_tree(struct Node **root)
{
    string temp;
    queue<Node *> queue;
    while (1)
    {
        cin >> temp;
        if (temp == "-1")
            break;

        if (temp == "null")
            *root = insert_node(*root, INT_MAX, queue);
        else
            *root = insert_node(*root, stoi(temp), queue);
    }
    *root = remove_null_nodes(*root);
    return;
}

Node *merge_two_binary_trees(Node *root1,Node *root2){
    if(root1 == NULL){
        return root2;
    }
    if(root2 == NULL){
        return root1;
    }

    root1->data += root2->data;
    root1->left = merge_two_binary_trees(root1->left,root2->left);
    root1->right = merge_two_binary_trees(root1->right ,root2->right);

    return root1;
}
void inorder_traversal(struct Node *node)
{
    if(node != NULL)
    {
        inorder_traversal(node->left);
        cout << node->data << " ";
        inorder_traversal(node->right);
    }
}

int main()
{
    build_tree(&root1);
    build_tree(&root2);

    merge_two_binary_trees(root1,root2);
    inorder_traversal(root1);
    return 0;
}
