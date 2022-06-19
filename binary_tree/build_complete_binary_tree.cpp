#include <iostream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
} * root;

struct Node *create_node(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

struct Node *build_complete_binary_tree(vector<int> &arr, int index)
{
    if (index >= arr.size())
        return NULL;

    struct Node *node = create_node(arr[index]);
    node->left = build_complete_binary_tree(arr, 2 * index + 1);
    node->right = build_complete_binary_tree(arr, 2 * index + 2);
    return node;
}

void insert_nodes()
{
    vector<int> arr;
    int temp;
    while (cin >> temp)
        arr.push_back(temp);

    root = build_complete_binary_tree(arr, 0);
}

void pre_order_traverse(struct Node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        pre_order_traverse(temp->left);
        pre_order_traverse(temp->right);
    }
}

void inorder(Node *root){
    stack<Node *> s;
    Node* curr = root;
    // s.push(curr);

    while(!s.empty() || curr != NULL){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout << curr->data << endl;

        curr = curr->right;
    }
}

void preorder(Node* root){
    stack<Node *> s;
    Node *curr = root;
    s.push(root);
    while(!s.empty()){
        curr = s.top();
        s.pop();

        cout << curr->data;

        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
    }
}

void postorder(Node *a){
    stack<Node *> s1,s2;

    s1.push(a);
    while(!s1.empty()){
        Node *n = s1.top();
        s1.pop();

        s2.push(n);
        if(n->left){
            s1.push(n->left);
        }
        if(n->right){
            s1.push(n->right);
        }
    }

    while(!s2.empty()){
        Node *n = s2.top();
        s2.pop();

        cout << n->data << " ";
    }
}

int main()
{
    insert_nodes();
    pre_order_traverse(root);
    return 0;
}
