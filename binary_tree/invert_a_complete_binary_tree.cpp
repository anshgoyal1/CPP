#include <iostream>
#include <vector>
#include <climits>
#include <queue>
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

Node *invert_tree(Node *node){
    if(node->left == NULL && node->right == NULL){
        return NULL;
    }

    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    node->left = invert_tree(node->left);
    node->right = invert_tree(node->right);

    return node;
}

void post_order_traversal(Node *root){
    if(root == NULL){
        return;
    }
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    cout << root->data << " ";
}
int main()
{
    build_tree();
    root = invert_tree(root);
    post_order_traversal(root);
    return 0;
}
