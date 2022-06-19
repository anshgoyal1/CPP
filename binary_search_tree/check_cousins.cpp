#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

struct NodeDetails
{
    int data;
    int level;
    Node *parent;
};

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

void build_tree(Node **root)
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
    *root = newNode(arr[0]);
    queue<Node *> queue;
    queue.push(*root);

    insert_nodes(arr, queue, 1);
}

void inorder(Node *root, Node *parent, int level, NodeDetails &x, NodeDetails &y)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, root, level + 1, x, y);

    if (root->data == x.data)
    {
        x.level = level;
        x.parent = parent;
    }
    else if (root->data == y.data)
    {
        y.level = level;
        y.parent = parent;
    }

    inorder(root->right, root, level + 1, x, y);
}

int check_cousins(Node *root, int m, int n)
{
    NodeDetails x = {m, 1, NULL};
    NodeDetails y = {n, 1, NULL};

    inorder(root, NULL, 1, x, y);

    if (x.level == y.level)
        &&(x.parent != y.parent)
        {
            return 1;
        }
    return 0;
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
        int m, n;
        cin >> m >> n;
        Node *root;
        build_tree(&root);

        cout << check_cousins(root, m, n) << endl;
        delete_tree(root);
    }
    return 0;
}
