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
    while (1)
    {
        cin >> temp;
        if (temp == "-1")
            break;

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

bool check_valid_bst(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (min != INT_MIN && root->data <= min)
        return false;
    if (max != INT_MAX && root->data >= max)
        return false;

    return check_valid_bst(root->left, min, root->data) && check_valid_bst(root->right, root->data, max);
}

void delete_tree(Node *root)
{
    if (root == NULL)
        return;
    delete_tree(root->right);
    delete_tree(root->left);
    delete root;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        build_tree();
        cout << check_valid_bst(root, INT_MIN, INT_MAX) << endl;
        delete_tree(root);
    }
    return 0;
}
