#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
}*root;

Node *insert_node(Node *root,int value){
    Node *new_node = new Node(value);

    if(root == NULL){
        root = new_node;
    }else if(root->data > new_node->data){
        root->left = insert_node(root->left,value);
    }else if(root->data  < value){
        root->right = insert_node(root->right,value);
    }

    return root;
}

void create_tree(){
    int x;
    while(cin >> x){
        if(x == -1){
            break;
        }
        root = insert_node(root,x);
    }
}

int find_height(Node *root){
    if(root == NULL){
        return 0;
    }

    int left = find_height(root->left);
    int right = find_height(root->right);

    return max(left,right) + 1;
}
void postorder_traverse(Node *root) {
    if(root == NULL){
        return;
    }

    postorder_traverse(root->left);
    postorder_traverse(root->right);
    cout << root->data << " ";
}

void level_order(Node *root){
    if(root == NULL){
        return;
    }

    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *current = q.front();
        cout << current->data << " ";

        if(current->left)
        q.push(current->left);

        if(current->right)
        q.push(current->right);

        q.pop();
    }
}

void pre_order(Node *root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(Node *root,vector<int> &temp){
    if(root == NULL){
        return;
    }
    in_order(root->left,temp);
    temp.push_back(root->data);
    in_order(root->right,temp);
}

int max(Node *root){
    while(root->right){
        root = root->right;
    }
    return root->data;
}

int min(Node *root){
    while(root->left){
        root = root->left;
    }
    return root->data;
}
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

Node *delete_node(Node *root,int value){
    if(root == NULL){
        return NULL;
    }else if(root->data < value){
        root->right = delete_node(root->right,value);
    }else if(root->data > value){
        root->left = delete_node(root->left,value);
    }else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            Node *temp = root;
            root= root->right;
            delete temp;
        }else{
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right,temp->data);
        }
    }
    return root;
}

Node *getSuccessor(Node *root,Node *current){
    if(current == NULL){
        return NULL;
    }else if(current->right){
        return FindMin(current->right);
    }else{
        Node *successor = NULL;
        Node *ancestor = root;

        while(ancestor != current){
            if(current->data <  ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

bool isBST(Node *root,int min,int max){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }

    return isBST(root->left,min,root->data) 
    && isBST(root->right,root->data,max);
}
Node* minValueNode(Node *root){
    Node *curr = root;
    while(curr && curr->left)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteNode(Node *root,int key){
    if(root == NULL){
        return root;
    }
    else if(root->data < key){
        root->right = deleteNode(root->right,key);
    }else if(root->data > key){
        root->left = deleteNode(root->left,key);
    }else{
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,key);
    }
    return root;
}

Node *constructFromPre(int pre[],int &preIndex,int low,int high,int size){
    if(preIndex >= size || low > high){
        return NULL;
    }

    Node *new_node = new Node(pre[preIndex]);
    preIndex++;

    if(low == high){
        return new_node;
    }

    int i;
    for(i = low;i<=high;i++){
        if(pre[i] > new_node->data){
            break;
        }
    }

    new_node->left = constructFromPre(pre,preIndex,low,i-1,size);
    new_node->right = constructFromPre(pre,preIndex,i+1,high,size);

    return new_node;
}
int in = 0;
void inorder2(vector<int> &temp,Node *root){
    if(root != NULL){
        inorder2(temp,root->left);
        temp.push_back(root->data);
        inorder2(temp,root->right);
    }
}
int sum = 0;
void reverse_inorder(Node *root){
    if(root != NULL){
        reverse_inorder(root->right);

        sum += root->data;
        root->data = sum;
        reverse_inorder(root->left);
    }
}
Node *conversion(Node *root){
    vector<int> temp;
    in_order(root,temp);
    sort(temp.begin(),temp.end());
    inorder2(temp,root);
}

Node *searchNode(Node *root,int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if(root->data > key){
        return searchNode(root->left,key);
    }
    return searchNode(root->right,key);
}

Node *minValueNode(Node *root){
    Node *curr = root;
    while(curr && curr->left){
        curr = curr->left;
    }
    return curr;
}

Node *deleteNode(Node *root,int key){
    if(root == NULL){
        return root;
    }
    else if(root->data > key){
        root->left = deleteNode(root->left,key);
    }else if(root->data < key){
        root->right = deleteNode(root->right,key);
    }else{
        if(root->left == NULL){
            Node *temp = root->right;
            delete(root);
            return temp;
        }else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,key);
    }
    return root;
}

Node *constructFromPreorder(int pre[],int &index,int size,int low,int high){
    if(index >= size || low > high){
        return NULL;
    }

    Node *root = new Node(pre[index++]);
    if(low == high){
        return root;
    }
    int i;
    for(i = low;i <= high;i++){
        if(pre[i] > root->data){
            break;
        }
    }

    root->left = constructFromPreorder(pre,index,size,low,i-1);
    root->right = constructFromPreorder(pre,index,size,i,high);
    return root;
}
void convertToBST(Node *root,vector<int> a,int &i){
    if(root != NULL){
        convertToBST(root->left,a,i);
        root->data = a[i];
        i++;
        convertToBST(root->right,a,i);
    }
}
Node *binaryTreeToBST (Node *root)
{
    if(root == NULL){
        return root;
    }
    vector<int> a;
    inorder2(a,root);
    sort(a.begin(),a.end());
    int i = 0;
    convertToBST(root,a,i);
    return root;
}

Node *mergeTwoBST(Node *root1,Node *root2){
    vector<int> a;
    inorder2(a,root1);
    inorder2(a,root2);

    sort(a.begin(),a.end());
    Node *n;
    for(int i = 0;i<a.size();i++){
        insert_node(n,a[i]);
    }
    return n;
}
int main()
{
    create_tree();
    pre_order(root);
    cout << endl;
    level_order(root);
    return 0;
}
