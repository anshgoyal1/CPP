// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void frontBsckSplit(Node* source,Node** front,Node** back){
    Node* slow;
    Node* fast;
    slow = source;
    fast = source->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

Node* SortedMerge(Node* a,Node* b){
    Node* result = NULL;
    if(a == NULL){
        return b;
    }else if(b == NULL){
        return a;
    }

    if(a->data <= b->data){
        result = a;
        SortedMerge(a->next,b);
    }else{
        result = b;
        SortedMerge(a,b->next);
    }
    return result;
}
Node* mergeSort(Node* head) {
    // your code here
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* p =head;
    Node* a;
    Node* b;
    frontBsckSplit(p,&a,&b);

    mergeSort(a);
    mergeSort(b);

    Node* res = SortedMerge(a,b);
    return res;
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends