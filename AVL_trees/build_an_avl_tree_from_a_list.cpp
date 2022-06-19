#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
} * root;

Node *get_new_node(int &data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int get_height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

Node *rightRotate(Node *node)
{
    Node *pivot = node->left;
    Node *temp = pivot->right;
    pivot->right = node;
    node->left = temp;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    pivot->height = max(get_height(pivot->left), get_height(pivot->right)) + 1;
    return pivot;
}

Node *leftRotate(Node *node)
{
    Node *pivot = node->right;
    Node *temp = pivot->left;
    pivot->left = node;
    node->right = temp;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    pivot->height = max(get_height(pivot->left), get_height(pivot->right)) + 1;
    return pivot;
}

int get_balance_factor(Node *node)
{
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
        return (get_new_node(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(get_height(node->left), get_height(node->right));
    int balanceFactor = get_balance_factor(node);

    if (balanceFactor > 1)
    {
        if (data < node->left->data)
            return rightRotate(node);

        else if (data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balanceFactor < -1)
    {
        if (data > node->right->data)
            return leftRotate(node);

        else if (data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

void build_tree()
{
    string temp;
    while (cin >> temp){
        if(temp != "null"){
            root = insert(root,stoi(temp));
        }
    }
    return;
}

Node * minValueNode(Node* node)  
{  
    Node* current = node;  
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  

Node *deleteNode(Node *root,int key){
    if(root == NULL){
        return root;
    }

    if(key < root->data){
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right,key);
    }else{
        if(root->left == NULL || root->right == NULL){
            Node *temp = root->left?root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }else{
                *root = *temp;
            }
            free(temp);
        }else{
            Node *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right,temp->data);
        }
    }

    if(root == NULL){
        return root;
    }

    root->height = 1 + max(get_height(root->left),get_height(root->right));
    int balance = get_balance_factor(root);

    if(balance > 1 && get_balance_factor(root->left) >= 0){
        return rightRotate(root);
    }

    if(balance > 1 &&
    get_balance_factor(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 &&
    get_balance_factor(root->right) <= 0){
        return leftRotate(root);
    }

    if(balance < -1 &&
    get_balance_factor(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preorder_traversal(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
    return;
}

void postorder_traversal(Node *root){
    if(root == NULL){
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

int main()
{   
    int k;
    cin >> k;
    build_tree();
    deleteNode(root,k);
    postorder_traversal(root);
    return 0;
}
