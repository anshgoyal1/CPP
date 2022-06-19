#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
} * root;

Node *newNode(int key)
{
    Node *node = new Node;
    node->data = key;
    node->left = node->right = NULL;

    return node;
}

void insert_nodes(vector<int> &arr, queue<Node *> &queue, int index)
{
    while (1)
    {
        if (queue.size() == 0)
            break;
        Node *top = queue.front();
        queue.pop();
        if (index < arr.size())
        {
            if (arr[index] != INT_MAX)
            {
                top->left = newNode(arr[index]);
                queue.push(top->left);
            }
            else
            {
                top->left = NULL;
            }
            index++;
        }
        if (index < arr.size())
        {
            if (arr[index] != INT_MAX)
            {
                top->right = newNode(arr[index]);
                queue.push(top->right);
            }
            else
            {
                top->right = NULL;
            }
            index++;
        }
    }
}

void build_tree()
{
    string temp;
    vector<int> arr;
    while (cin >> temp)
    {
        if (temp != "null")
            arr.push_back(stoi(temp));
        else
            arr.push_back(INT_MAX);
    }
    root = newNode(arr[0]);
    queue<Node *> queue;
    queue.push(root);

    insert_nodes(arr, queue, 1);
}

void deleteNode(Node *&root, int key)
{
    if (root == NULL)
        return;

    if (key < root->data)
        deleteNode(root->left, key);
    else if (key > root->data)
        deleteNode(root->right, key);
    else
    {
        // Case 1: node to be deleted is a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        // Case 2: node to be deleted has two children
        else if (root->left && root->right)
        {
            // find its in-order predecessor node
            Node *predecessor = root->left;
            while (predecessor->right != NULL)
                predecessor = predecessor->right;

            root->data = predecessor->data;

            // recursively delete the predecessor.
            deleteNode(root->left, predecessor->data);
        }

        // Case 3: node to be deleted has only one child
        else
        {
            Node *child = (root->left) ? root->left : root->right;
            Node *node_to_delete = root;

            root = child;
            delete node_to_delete;
        }
    }
}

void postorder_traverse(Node *root)
{
    if (root == NULL)
        return;

    postorder_traverse(root->left);
    postorder_traverse(root->right);
    cout << root->data << " ";
}

int main()
{
    int K;
    cin >> K;
    build_tree();

    deleteNode(root, K);
    postorder_traverse(root);
    return 0;
}