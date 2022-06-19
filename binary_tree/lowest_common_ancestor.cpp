#include <iostream>
#include <cstdlib>
#include <climits>
#include <queue>
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

struct Node *remove_null_nodes(struct Node *root)
{
    if (root == NULL || root->data == INT_MAX)
        return NULL;

    root->left = remove_null_nodes(root->left);
    root->right = remove_null_nodes(root->right);

    return root;
}

struct Node *insert_node(struct Node *root, int value, queue<struct Node *> &queue)
{
    struct Node *new_node = create_node(value);
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
    queue<struct Node *> queue;
    while (cin >> temp)
    {
        if (temp == "null")
            root = insert_node(root, INT_MAX, queue);
        else
            root = insert_node(root, stoi(temp), queue);
    }
    root = remove_null_nodes(root);
}

bool findPath(Node *root,vector<int> &path,int k){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);

    if(root->data == k){
        return true;
    }

    if((root->left && findPath(root->left,path,k)) || 
        (root->right && findPath(root->right,path,k))){
            return true;
        }

    path.pop_back();
    return false;
}

int findLCA(Node *root,int n1,int n2){
    vector<int> path1,path2;

    if(!findPath(root,path1,n1) ||
        !findPath(root,path2,n2)){
            return -1;
        }


    int i;
    for(i = 0;i<path1.size() && i < path2.size();i++){
        if(path1[i] != path2[i]){
            break;
        }
    }
    return path1[i-1];
}

int main()
{
    int m,n;
    cin >> m >> n;
    build_tree();
    int path = findLCA(root,m,n);
    cout << path << endl;
    return 0;
}
