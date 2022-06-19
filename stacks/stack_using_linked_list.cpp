#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
}*top = NULL;

void push(int x){
	struct Node *t = new struct Node;
	if(t == NULL){
		cout << "Stack is full" << endl;
	}
	else{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int pop(){
	struct Node *t = new struct Node;
	int x = -1;
	if(top == NULL){
		cout << "Stack is empty" << endl;
	}
	else{
		t = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}

void display(){
	struct Node *p = top;
	while(p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main(){
	
}