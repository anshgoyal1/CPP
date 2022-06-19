#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
} * root;

struct Node *create_node(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

Node *build_tree(int start, int end, vector<int> const &pre_order, int &pre_ind, unordered_map<int, int> &map)
{
    // base case
    if (start > end)
        return nullptr;

    // The next element in pre_order[] will be the root node of subtree
    Node *root = create_node(pre_order[pre_ind++]);

    // get the index of root node in in_order to determine the left and right subtree
    int index = map[root->data];

    // recursively construct the left subtree
    root->left = build_tree(start, index - 1, pre_order, pre_ind, map);

    // recursively construct the right subtree
    root->right = build_tree(index + 1, end, pre_order, pre_ind, map);

    // return current node
    return root;
}

void build_tree(vector<int> const &in_order, vector<int> const &pre_order)
{
    int len = in_order.size();

    // create a map to efficiently find the index of an element in in_order sequence
    unordered_map<int, int> map;
    for (int i = 0; i < len; i++)
        map[in_order[i]] = i;

    // stores index of next unprocessed node in pre_order sequence
    int pre_index = 0;

    root = build_tree(0, len - 1, pre_order, pre_index, map);
}

void post_order_traversal(struct Node *node)
{
    if (node == NULL)
        return;

    post_order_traversal(node->left);
    post_order_traversal(node->right);
    cout << node->data << " ";
}

Node* mirror(Node* root){
    if(root == NULL){
        return root;
    }

    Node* t = root->left;
    root->left = root->right;
    root->left = t;

    if(root->left){
        mirror(root->left);
    }
    if(root->right){
        mirror(root->right);
    }

    return root;
}

void inorder_recurr(Node *root){
    stack<Node *> st;
    Node* curr = root;
    while(!st.empty() || curr != NULL){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }else{
            Node *t = st.top();
            st.pop();

            cout << curr->data << " ";
            curr = curr->right;
        }
    }

}

void preorder_recur(Node *root){
    if(root == NULL){
        return;
    }

    stack<Node *> st;
    st.push(root);
    while(!st.empty()){
        Node *temp = st.top();
        st.pop();

        cout << temp->data << " ";

        if(temp->right){
            st.push(temp->right);
        }

        if(temp->left){
            st.push(temp->left);
        }
    }
}

void diagonal1Print(Node *root,int d,map<int,vector<int>> &mp){
    if(!root){
        return;
    }

    mp[d].push_back(root->data);
    diagonal1Print(root->left,d+1,mp);
    diagonal1Print(root->right,d,mp);
}

void ques(Node *root){
    map<int,vector<int>> mp;
    diagonal1Print(root,0,mp);
    for(auto it:mp){
        vector<int> a = it.second;
        for(auto itr2:a){
            cout << itr2 << " ";
        }
        cout << endl;
    }
}

void get_vertical_nodes(Node *root,int hd,map<int,vector<int>> &mp){
    if(root == NULL){
        return;
    }

    mp[hd].push_back(root->data);

    get_vertical_nodes(root->left,hd-1,mp);
    get_vertical_nodes(root->right,hd+1,mp);

}

void get(Node *root){
    map<int,vector<int>> m;
    int hd = 0;
    get_vertical_nodes(root,hd,m);

    for(auto it:m){
        for(auto it2: it.second){
            cout << it2 << " ";
        }
    }
}
int main()
{
    int temp;
    vector<int> in_order;
    vector<int> post_order;

    while (1)
    {
        cin >> temp;
        if (temp == -1)
            break;
        post_order.push_back(temp);
    }
    while (1)
    {
        cin >> temp;
        if (temp == -1)
            break;
        in_order.push_back(temp);
    }

    build_tree(in_order, post_order);
    post_order_traversal(root);
    return 0;
}