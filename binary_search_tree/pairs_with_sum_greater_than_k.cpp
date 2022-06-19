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

bool search(Node *root,int val){
    if(root != NULL && val == root->data){
        return true;
    }
    else if(root->data > val){
        return search(root->left,val);
    }else if(root->data < val){
        return search(root->right,val);
    }
}

void getSum(Node *root1,Node *root2,int k,int &count){
    if(root1 == NULL || root2 == NULL){
        return;
    }

    int rem = k - root1->data;
    if(search(root2,rem)){
        count++;
    }
    getSum(root1->left,root2,k,count);
    getSum(root1->right,root2,k,count);
}

int main()
{
    int k;
    cin >> k;
    Node *root1,*root2;
    build_tree(&root1);
    build_tree(&root2);

    int count = 0;
    getSum(root1,root2,k,count);
    cout << count << endl;
    return 0;
}
