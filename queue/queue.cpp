#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    };
    // ~Queue();

    void enqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full";
        }
        else
        {
            rear++;
            Q[rear] = x;
        }
    }

    int dequeue()
    {
        int x = -1;
        if (rear == front)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            front++;
            x = Q[front];
        }
        return x;
    }

    void display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};

void reverse(queue<int> q)
{
    if (q.empty())
    {
        return;
    }
    else
    {
        int x = q.front();
        q.pop();
        reverse(q);

        q.push(x);
        return;
    }
}
struct Node
{
    struct Node *left, *right;
    int data;
};

void next_smalle_element(vector<int> a){
    int n = a.size();
    stack<int> st;
    st.push(0);
    for(int i = 1;i<n;i++){
        if(st.empty()){
            st.push(i);
            continue;
        }

        while(!st.empty() && a[st.top()] > a[i]){
            cout << a[i] << " ";
            st.pop();
        }

        st.push(i);
    }

    
}

bool areAnagrams(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while (1)
    {
        int n1 = q1.size();
        int n2 = q2.size();

        if (n1 != n2)
        {
            return false;
        }

        if (n1 == 0)
        {
            break;
        }

        vector<int> curr_level1, curr_level2;
        while (n1 > 0)
        {
            Node *node1 = q1.front();
            q1.pop();
            if (node1->left != NULL)
                q1.push(node1->left);
            if (node1->right != NULL)
                q1.push(node1->right);
            n1--;

            Node *node2 = q2.front();
            q2.pop();
            if (node2->left != NULL)
                q2.push(node2->left);
            if (node2->right != NULL)
                q2.push(node2->right);

            curr_level1.push_back(node1->data);
            curr_level2.push_back(node2->data);
        }

        sort(curr_level1.begin(), curr_level1.end());
        sort(curr_level2.begin(), curr_level2.end());
        if (curr_level2 != curr_level1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    return 0;
}