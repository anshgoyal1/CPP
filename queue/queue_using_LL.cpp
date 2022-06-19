#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*front = NULL,*rear = NULL;

void enqueue(int x){
    struct Node *t = new Node;
    if(t == NULL){
        cout << "Queue is Full" << endl;
    }else{
        t->data = x;
        t->next = NULL;
        if(front == NULL){
            front = rear = t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(){
    int x = -1;
    Node *p;
    if(front == NULL){
        cout << "Queue is empty" << endl; 
    }else{
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display(){
    struct Node *p = front;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    cout  << dequeue() << endl;
}